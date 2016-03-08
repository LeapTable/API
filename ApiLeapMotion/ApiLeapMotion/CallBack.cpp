#include "stdafx.h"
#include "CallBack.h"

#include "UIButton.h"

void		OnClickTest(void *sender, void *arg)
{
	UIButton *button = static_cast<UIButton*>(sender);

	std::cout << "on ClickText : " << button->getTag() << std::endl;
}


void	OnButtonClick_1(void *sender, void*args)
{
	UIButton *button = static_cast<UIButton*>(sender);

	std::cout << "OnButtonClick_1 : " << button->getTag() << std::endl;

	button->setPosX(button->getPosX() + 10);
}