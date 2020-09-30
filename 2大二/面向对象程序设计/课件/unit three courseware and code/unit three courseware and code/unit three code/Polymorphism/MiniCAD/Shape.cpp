// Shape.cpp : implementation file
//

#include "stdafx.h"
#include "MyCad.h"
#include "Shape.h"
#include ".\shape.h"


IMPLEMENT_SERIAL( CShape, CObject, 1 )

// CShape


// CShape member functions

void CShape::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{	// storing code
		ar << m_nColor;
	}
	else
	{	// loading code
		ar >> m_nColor;
	}
}
