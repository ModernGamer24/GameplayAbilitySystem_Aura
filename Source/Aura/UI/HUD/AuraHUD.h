// Aura learning project. xModern 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class UAuraUserWidget;

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WParams);

	void InitOverlay(APlayerController* Controller, APlayerState* State, UAbilitySystemComponent* System, UAttributeSet* Set);

protected:
	
	UPROPERTY(EditDefaultsOnly, Category="WidgetOverrides")
	TSubclassOf<UUserWidget> OverlayWidgetClass;


private:

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerBpClass;
	
	
};
