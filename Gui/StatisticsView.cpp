///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// Project Libraries
#include "StatisticsView.h"
#include "ui_StatisticsView.h"


////////////////////////////
/// CLASS IMPLEMENTATION ///
////////////////////////////
// Class Constructor
StatisticsView::StatisticsView(BankController* controller, QWidget *parent) :
        controller{controller}, QWidget(parent), ui(new Ui::StatisticsView) {
    ui->setupUi(this);
    this->processInquiries();

    /// VIEW CONFIGURATION
    // Create buttons for chart type selection
    QPushButton *barChartButton = new QPushButton("Bar Chart", this);
    QPushButton *pieChartButton = new QPushButton("Pie Chart", this);

    // Create the layout for buttons
    QVBoxLayout *buttonLayout = new QVBoxLayout();
    buttonLayout->addWidget(barChartButton);
    buttonLayout->addWidget(pieChartButton);

    // Create the drawing area
    drawingArea = new QWidget(this);
    drawingArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Create the main layout
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(drawingArea);
    mainLayout->addLayout(buttonLayout);

    // Connect buttons to their respective slots
    connect(barChartButton, &QPushButton::clicked, this, &StatisticsView::showBarChart);
    connect(pieChartButton, &QPushButton::clicked, this, &StatisticsView::showPieChart);

    // Set the layout for the main widget
    this->setLayout(mainLayout);

    // Prepare data for drawing
    this->processInquiries();
}

// Class Destructor
StatisticsView::~StatisticsView() {
    delete ui;
}

// Observer Notification to redraw graph
void StatisticsView::notify() {
    this->processInquiries();
    this->update();
}

// Update Chart based on selected Type
void StatisticsView::showBarChart() {
    currentChartType = ChartType::Bar;
    this->update();
}

// Update Chart based on selected Type
void StatisticsView::showPieChart() {
    currentChartType = ChartType::Pie;
    this->update();
}

// Data Processing for Graph Visualization
void StatisticsView::processInquiries() {
    departmentCounts.clear();

    // Get the range of completed inquiries
    auto [begin, end] = controller->getCompleted();

    // Count inquiries per department
    for (auto it = begin; it != end; ++it) {
        const Inquiry& inquiry = *it;
        QString department = QString::fromStdString(toString(inquiry.getAssignedDepartment()));
        departmentCounts[department]++;
    }
}

// Painting the Graph
void StatisticsView::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    switch (currentChartType) {
        case ChartType::Bar:
            drawBarChart(painter);
            break;
        case ChartType::Pie:
            drawPieChart(painter);
            break;
    }
}

// Painting the Graph - Bar Chart
void StatisticsView::drawBarChart(QPainter &painter) {
    painter.setPen(QPen(Qt::black, 2));
    painter.setBrush(QBrush(Qt::blue));

    // Increased padding and spacing
    int padding = 80;
    int spacing = 30;
    int availableWidth = width() - 2 * padding;
    int numDepartments = departmentCounts.size();

    // No data to display
    if (numDepartments == 0) {
        painter.setPen(Qt::black);
        painter.drawText(10, height() / 2, "No data available");
        return;
    }

    // Calculate bar width
    int barWidth = std::max(availableWidth / (numDepartments * 2), 20);

    // Find the maximum count for scaling
    int maxCount = 0;
    for (const auto& count : departmentCounts) {
        if (count > maxCount) {
            maxCount = count;
        }
    }

    int maxHeight = height() - 2 * padding - 50;
    if (maxCount == 0) {
        maxHeight = 0;
    }

    // Draw axes
    painter.setPen(QPen(Qt::black, 2));
    painter.drawLine(padding, height() - padding, width() - padding, height() - padding); // X-axis
    painter.drawLine(padding, height() - padding, padding, padding); // Y-axis

    // Draw the bars
    int x = padding + spacing;
    for (auto it = departmentCounts.begin(); it != departmentCounts.end(); ++it) {
        int barHeight = (maxCount > 0) ? (it.value() / static_cast<double>(maxCount)) * maxHeight : 0;

        // Ensure drawing coordinates are within bounds
        int y = height() - padding - barHeight;
        if (x < width() - padding) {
            painter.setBrush(Qt::blue);
            painter.drawRect(x, y, barWidth, barHeight);

            // Draw the department name and count next to the bar
            painter.setPen(Qt::black);
            painter.drawText(x + barWidth / 2, y - 5, it.key() + ": " + QString::number(it.value()));
        }
        x += barWidth + spacing;
    }
}

// Painting the Graph - Pie Chart
void StatisticsView::drawPieChart(QPainter &painter) {
    painter.setPen(QPen(Qt::black, 2));

    int total = 0;
    for (auto it = departmentCounts.begin(); it != departmentCounts.end(); ++it) {
        total += it.value();
    }

    if (total == 0) {
        painter.setPen(Qt::black);
        painter.drawText(10, height() / 2, "No data available");
        return;
    }

    int startAngle = 0;
    int radius = std::min(width(), height()) / 2 - 50;
    QPoint center(width() / 2, height() / 2);

    // Create a list of angles for labeling
    QList<QPair<int, QString>> labels;
    for (auto it = departmentCounts.begin(); it != departmentCounts.end(); ++it) {
        int count = it.value();
        QString department = it.key();
        int spanAngle = static_cast<int>(360.0 * count / total);

        // Draw pie slice
        painter.setBrush(QColor(rand() % 256, rand() % 256, rand() % 256));
        painter.drawPie(center.x() - radius, center.y() - radius, 2 * radius, 2 * radius, startAngle * 16, spanAngle * 16);

        // Prepare label for this slice
        labels.append(QPair<int, QString>(startAngle + spanAngle / 2, department));

        // Update start angle for next slice
        startAngle += spanAngle;
    }

    // Draw labels
    painter.setPen(Qt::white);
    for (const auto& label : labels) {
        int angle = label.first;
        QString department = label.second;

        // Calculate label position
        double radian = qDegreesToRadians(angle);
        int x = center.x() + (radius + 30) * cos(radian);
        int y = center.y() - (radius + 30) * sin(radian);

        // Draw the label
        painter.drawText(x, y, department);
    }
}