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

// Data Processing for Graph Visualization
void StatisticsView::processInquiries() {
    this->departmentCounts.clear();
    std::vector<Inquiry> inquiries = controller->getInquiries();
    for (const auto& inquiry : inquiries) {

        // Insert in the Statistics Map
        QString department = QString::fromStdString(toString(inquiry.getAssignedDepartment()));
        if (departmentCounts.contains(department)) {
            departmentCounts[department]++;
        } else {
            departmentCounts[department] = 1;
        }
    }
}

// Painting the Graph
void StatisticsView::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    // Set up the pen and brush
    painter.setPen(Qt::black);
    painter.setBrush(Qt::blue);

    // Calculate bar widths and heights
    int barWidth = width() / (departmentCounts.size() * 2);
    int maxCount = 0;
    for (const auto& count : departmentCounts) {
        if (count > maxCount) {
            maxCount = count;
        }
    }
    int maxHeight = height() - 40;

    // Draw the bars
    int x = 20;
    for (auto it = departmentCounts.begin(); it != departmentCounts.end(); ++it) {
        int barHeight = (it.value() / static_cast<double>(maxCount)) * maxHeight;
        painter.drawRect(x, height() - barHeight - 20, barWidth, barHeight);

        // Draw the department name below the bar
        painter.drawText(x, height() - 5, it.key());
        x += barWidth * 2;
    }
}
