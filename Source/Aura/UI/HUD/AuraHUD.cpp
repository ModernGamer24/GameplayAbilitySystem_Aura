// Aura learning project. xModern 2024


#include "AuraHUD.h"

#include "Aura/UI/Widget/AuraUserWidget.h"
#include "Aura/UI/WidgetController/Overlay/OverlayWidgetController.h"
#include "Blueprint/UserWidget.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerBpClass);
		OverlayWidgetController->SetWidgetControllerParams(WParams);
		OverlayWidgetController->BindCallbackDependencies();
		
		return OverlayWidgetController;
	}
	else
	{
		return OverlayWidgetController;
	}
}

void AAuraHUD::InitOverlay(APlayerController* Controller, APlayerState* State, UAbilitySystemComponent* System,
	UAttributeSet* Set)
{
	checkf(OverlayWidgetClass, TEXT("Overlay widget class is null, set this in AuraHud class BP"))
	checkf(OverlayWidgetControllerBpClass, TEXT("Overlay widget controller class is null, set this in AuraHud class BP"))

	
	OverlayWidget = CreateWidget<UAuraUserWidget>(GetWorld(), OverlayWidgetClass);


	const FWidgetControllerParams WidgetControllerParams(Controller, State, System, Set);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	
	OverlayWidget->AddToViewport(0);
}
