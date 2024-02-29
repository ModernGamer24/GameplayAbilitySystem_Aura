// Aura learning project. xModern 2024


#include "AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetParams)
{
	PlayerController = WidgetParams.PlayerController;
	PlayerState = WidgetParams.PlayerState;
	AbilitySystemComponent = WidgetParams.AbilitySystemComponent;
	AttributeSet = WidgetParams.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
	
}

void UAuraWidgetController::BindCallbackDependencies()
{
}
