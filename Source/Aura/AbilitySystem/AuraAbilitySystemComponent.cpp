// Aura learning project. xModern 2024


#include "AuraAbilitySystemComponent.h"

#include "Aura/Aura.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& EffectSpec,
                                                FActiveGameplayEffectHandle EffectHandle)
{
	// We get all tags applied with this effect
	FGameplayTagContainer AssetTagContainer;
	EffectSpec.GetAllAssetTags(AssetTagContainer);
	
	OnEffectApplied.Broadcast(AssetTagContainer);
	
}
