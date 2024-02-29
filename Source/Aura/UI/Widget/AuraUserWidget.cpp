// Aura learning project. xModern 2024


#include "AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* NewController)
{
	WidgetController = NewController;
	OnWidgetControllerSet();
}
