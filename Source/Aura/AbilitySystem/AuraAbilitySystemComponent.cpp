// Aura learning project. xModern 2024


#include "AuraAbilitySystemComponent.h"

#include "Aura/Aura.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& Effect,
                                                FActiveGameplayEffectHandle Handle)
{
	PRINT("Effect Applied")
}
