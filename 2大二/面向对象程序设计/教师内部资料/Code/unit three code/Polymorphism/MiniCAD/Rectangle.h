#pragma once
#include "shape.h"

class CRectangle :
	public CShape
{
	DECLARE_SERIAL( CRectangle )

	CRectangle(void):
		m_nStyle(PS_SOLID),m_nWidth(1) {m_nColor = RGB(255,255,255); };
	CRectangle(const CPoint& p1, const CPoint& p2):
		m_nStyle(PS_SOLID),m_nWidth(1), m_p1(p1),m_p2(p2) { m_nColor = RGB(255,255,255); };
	CRectangle(const CPoint& p1, const CPoint& p2, COLORREF c):
		m_nStyle(PS_SOLID),m_nWidth(1), m_p1(p1),m_p2(p2) { m_nColor = c; };
	~CRectangle(void){};

	void Draw(CDC *pDC);
	void Resize(const CPoint& p) { m_p2 = p; };
	bool IsSelected(const CPoint& p);
	void Move(int dx, int dy) {
		m_p1.x += dx, m_p1.y += dy;
		m_p2.x += dx, m_p2.y += dy;
	}
	bool Modify();
	CShape* Clone() {
		CRectangle *p = new CRectangle(m_p1,m_p2, m_nColor);
		p->m_nStyle = m_nStyle;
		p->m_nWidth = m_nWidth;
		return p;
	}
	CRect GetRect() { return CRect(m_p1,m_p2); };
private:
	CPoint m_p1,m_p2;
	int m_nStyle, m_nWidth;
public:
	virtual void Serialize(CArchive& ar);

};
