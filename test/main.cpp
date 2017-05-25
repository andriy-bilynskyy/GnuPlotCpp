#include "gtest/gtest.h"
#include "CPlot2D.h"
#include <math.h>


class GnuPlotTest : public ::testing::Test {
public:
    GnuPlotTest() : m_plot()
    {

    }

protected:
    CPlot2D m_plot;
};

TEST_F(GnuPlotTest, sin)
{
    ASSERT_TRUE(CPlot2D::checkGNUPLOT());
    m_plot.setXlable("time, mS");
    m_plot.setYlable("voltage, V");
    double x = -M_PI;
    while(x <= M_PI)
    {
        m_plot.addPoint(x, sin(x));
        x += .0001;
    }
    m_plot.setColor(0xFF0000);
    m_plot.setTitle("sin(x)");
    m_plot.draw();
    m_plot.resetData();
}

TEST_F(GnuPlotTest, cos)
{
    ASSERT_TRUE(CPlot2D::checkGNUPLOT());
    double x = -M_PI;
    while(x <= M_PI)
    {
        m_plot.addPoint(x, cos(x));
        x += .0001;
    }
    m_plot.setColor(0x00FF00);
    m_plot.setTitle("cos(x)");
    m_plot.draw();
    m_plot.resetPlot();
}

TEST_F(GnuPlotTest, exp)
{
    ASSERT_TRUE(CPlot2D::checkGNUPLOT());
    double x = -M_PI;
    while(x <= M_PI)
    {
        m_plot.addPoint(x, exp(x));
        x += .0001;
    }
    m_plot.draw();
    m_plot.resetData();
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}


