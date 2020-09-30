#pragma once
#include "shape.h"

class CLine : public CShape
{
public:
	DECLARE_SERIAL( CLine )

	CLine(void):
		m_nStyle(PS_SOLID),m_nWidth(1) { }
	CLine(const CPoint& p1, const CPoint& p2):
		m_nStyle(PS_SOLID),m_nWidth(1),m_p1(p1),m_p2(p2) {  }
	~CLine(void){}

	void Draw(CDC *pDC);
	void Resize(const CPoint& p) { m_p2 = p; }
	bool IsSelected(const CPoint& p);
	void Move(int dx, int dy) {
		m_p1.x += dx, m_p1.y += dy;
		m_p2.x += dx, m_p2.y += dy;
	}
	bool Modify();
	CShape* Clone() { 
		CLine *p = new CLine(m_p1,m_p2);
		p->m_nColor = m_nColor;
		p->m_nStyle = m_nStyle;
		p->m_nWidth = m_nWidth;
		return p;
	}
	CRect GetRect() { return CRect(m_p1,m_p2); }
private:
	CPoint m_p1,m_p2;
	int m_nStyle, m_nWidth;
public:
	virtual void Serialize(CArchive& ar);
};
