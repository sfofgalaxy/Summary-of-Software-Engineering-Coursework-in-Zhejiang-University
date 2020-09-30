#pragma once
#include "shape.h"
#include "math.h"

class CPolygon : public CShape
{
public:
	DECLARE_SERIAL( CPolygon )

	CPolygon(void):
		m_nStyle(PS_SOLID),m_nWidth(1), points(0), num(0) { m_nColor = RGB(255,255,255); };
	CPolygon(CPoint *ptList, int ptCount):
		m_nStyle(PS_SOLID),m_nWidth(1),points(0),num(ptCount) {
		m_nColor = RGB(255,255,255);
		if (ptCount > 0) {
			points = new CPoint[num];
			m_p1 = m_p2 = points[0] = ptList[0];
			for (int i=1; i<num; ++i) {
				points[i] = ptList[i];
				if (points[i].x < m_p1.x) m_p1.x = points[i].x;
				if (points[i].y < m_p1.y) m_p1.y = points[i].y;
				if (points[i].x > m_p2.x) m_p2.x = points[i].x;
				if (points[i].y > m_p2.y) m_p2.y = points[i].y;
			}
		}
	};

	virtual ~CPolygon(void){
		delete[] points;
	}

	void Draw(CDC *pDC);
	void Resize(const CPoint& p) {
		int xdif = p.x-m_p2.x;
		int ydif = p.y-m_p2.y;
		double xScale = double(p.x-m_p1.x)/(m_p2.x-m_p1.x);
		double yScale = double(p.y-m_p1.y)/(m_p2.y-m_p1.y);

		for (int i=0; i<num; ++i) {
			points[i].x = m_p1.x + int((points[i].x-m_p1.x) * xScale + 0.5);
			points[i].y = m_p1.y + int((points[i].y-m_p1.y) * yScale + 0.5);
		}
		m_p2 = p;
	}
	bool IsSelected(const CPoint& p);
	void Move(int dx, int dy) {
		for (int i=0; i<num; ++i) {
			points[i].x+=dx; points[i].y+=dy;
		}
		m_p1.x += dx, m_p1.y += dy;
		m_p2.x += dx, m_p2.y += dy;
	}
	bool Modify();
	CShape* Clone() {
		CPolygon *p = new CPolygon(points,num);
		p->m_nColor = m_nColor;
		p->m_nStyle = m_nStyle;
		p->m_nWidth = m_nWidth;
		return p;
	}

	CRect GetRect() { return CRect(m_p1,m_p2); };
private:
	CPolygon(const CPolygon&);
	CPolygon& operator=(const CPolygon&);
	CPoint *points;
	int num;
	CPoint m_p1,m_p2;
	int m_nStyle, m_nWidth;
public:
	virtual void Serialize(CArchive& ar);
};
