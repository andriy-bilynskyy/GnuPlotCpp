#include "CPlot2D.h"
#include <stdio.h>

const char * CPlot2D::m_gnuplotPipe = "gnuplot -persist";

CPlot2D::CPlot2D() : m_data(), m_color(0),
                     m_title("plot"), m_xlable("x"), m_ylable("y")
{
}

CPlot2D::~CPlot2D()
{
}

void CPlot2D::addPoint(double x, double y)
{
    Point2D_t p(x, y);
    m_data.push_back(p);
}

void CPlot2D::resetData()
{
    m_data.clear();
}

void CPlot2D::resetPlot()
{
    m_data.clear();
    m_color = 0;
    m_title = "plot";
    m_xlable = "x";
    m_ylable = "y";
}

void CPlot2D::setColor(uint32_t rrggbb)
{
    m_color = rrggbb & 0xFFFFFF;
}

void CPlot2D::setTitle(const char * title)
{
    m_title = title;
}

void CPlot2D::setXlable(const char * lable)
{
    m_xlable = lable;
}

void CPlot2D::setYlable(const char * lable)
{
    m_ylable = lable;
}

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

void CPlot2D::draw()
{
    FILE *gp = popen(m_gnuplotPipe, "w");
    if(gp)
    {
        fprintf(gp,
           "set term wxt title '%s'\n", m_title);
        fprintf(gp,
           "set xlabel '%s'\n set ylabel '%s'\n", m_xlable, m_ylable);
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

