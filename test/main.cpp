#include "gtest/gtest.h"
#include "CPlot2D.h"
#include <math.h>


class GnuPlotTest : public ::testing::Test {
};

CPlot2D plot;

TEST_F(GnuPlotTest, sin)
{
    ASSERT_TRUE(CPlot2D::checkGNUPLOT());
    plot.setXlable("time, mS");
    plot.setYlable("voltage, V");
    double x = -M_PI;
    while(x <= M_PI)
    {
        plot.addPoint(x, sin(x));
        x += .0001;
    }
    plot.setColor(0xFF0000);
    plot.setTitle("sin(x)");
    plot.draw();
    plot.resetData();
}

TEST_F(GnuPlotTest, cos)
{
    ASSERT_TRUE(CPlot2D::checkGNUPLOT());
    double x = -M_PI;
    while(x <= M_PI)
    {
        plot.addPoint(x, cos(x));
        x += .0001;
    }
    plot.setColor(0x00FF00);
    plot.setTitle("cos(x)");
    plot.draw();
    plot.resetPlot();
}

TEST_F(GnuPlotTest, exp)
{
    ASSERT_TRUE(CPlot2D::checkGNUPLOT());
    double x = -M_PI;
    while(x <= M_PI)
    {
        plot.addPoint(x, exp(x));
        x += .0001;
    }
    plot.draw();
    plot.resetData();
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


