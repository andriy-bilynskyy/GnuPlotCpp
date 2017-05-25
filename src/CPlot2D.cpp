#include "CPlot2D.h"
#include <stdio.h>

/**
 * GNU plot pipe to work with.
 */
const char * CPlot2D::m_gnuplotPipe = "gnuplot -persist";

/**
 * Default class constructor.
 */
CPlot2D::CPlot2D() : m_data(), m_color(0),
                     m_title("plot"), m_xlabel("x"), m_ylabel("y")
{
}

/**
 * Class destructor.
 */
CPlot2D::~CPlot2D()
{
}

/**
 * Add point to plot.
 * @param x - X coordinate
 * @param y - Y coordinate
 */
void CPlot2D::addPoint(double x, double y)
{
    Point2D_t p(x, y);
    m_data.push_back(p);
}

/**
 * Remove all points from plot.
 */
void CPlot2D::resetData()
{
    m_data.clear();
}

/**
 * Remove all points from plot. And set all plot settings by default.
 */
void CPlot2D::resetPlot()
{
    m_data.clear();
    m_color = 0;
    m_title = "plot";
    m_xlabel = "x";
    m_ylabel = "y";
}

/**
 * Set plot line color, black by default.
 * @param rrggbb - color in format RRGGBB
 */
void CPlot2D::setColor(uint32_t rrggbb)
{
    m_color = rrggbb & 0xFFFFFF;
}

/**
 * Set plot title, "plot" by default.
 * @param title - title string
 */
void CPlot2D::setTitle(const char * title)
{
    m_title = title;
}

/**
 * Set X axis title, "x" by default.
 * @param label - X axis label string
 */
void CPlot2D::setXlable(const char * label)
{
    m_xlabel = label;
}

/**
 * Set Y axis title, "y" by default.
 * @param label - Y axis label string
 */
void CPlot2D::setYlable(const char * label)
{
    m_ylabel = label;
}

/**
 * Check if gnuplot is available in the  system.
 * @return true if available otherwise false
 */
bool CPlot2D::checkGNUPLOT()
{
    bool result = false;
    FILE *gp = popen(m_gnuplotPipe, "w");
    if(gp)
    {
        (void)pclose(gp);
        result = true;
    }
    return result;
}

/**
 * Draw plot window.
 */
void CPlot2D::draw()
{
    FILE *gp = popen(m_gnuplotPipe, "w");
    if(gp)
    {
        fprintf(gp,
           "set term wxt title '%s'\n", m_title);
        fprintf(gp,
           "set xlabel '%s'\n set ylabel '%s'\n", m_xlabel, m_ylabel);
        fprintf(gp,
           "plot '-' lc rgb '#%06X' with lines title '%s'\n", m_color, m_title);
        for(std::vector<Point2D_t>::iterator it =
                                       m_data.begin(); it != m_data.end(); ++it)
        {
            fprintf(gp, "%g %g\n", (double)(it->x), (double)(it->y));
        }
        fprintf(gp, "e\n");
        fflush(gp);
        (void)pclose(gp);
    }
}

