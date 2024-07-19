#include "window.h"
#include "class1.h"
UWindow::UWindow()
{
	LOGAR("CRIOU", "   ");
}

UWindow::~UWindow()
{
	LOGAR("destruiu", "   ");
	delete u;
}

void UWindow::inicializar()
{
}
