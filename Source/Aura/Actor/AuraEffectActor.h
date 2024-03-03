// Aura learning project. xModern 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "AuraEffectActor.generated.h"

class UAbilitySystemComponent;
class UBoxComponent;
class UGameplayEffect;

UENUM(BlueprintType)
enum class EEffectApplicationPolicy : uint8
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};
UENUM(BlueprintType)
enum class EEffectRemovalPolicy : uint8
{
	RemoveOnOverlap,
	DoNotRemove
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();



protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Victim, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* Target);

	UFUNCTION(BlueprintCallable)
	void EndOverlap(AActor* Target);

	UPROPERTY(EditAnywhere, Category="Applied Effects", BlueprintReadOnly)
	bool bDestroyOnEffectRemoval = false;

	UPROPERTY(EditAnywhere, Category="Applied Effects | Instant", BlueprintReadOnly)
	EEffectApplicationPolicy InstantEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	
	UPROPERTY(EditAnywhere, Category="Applied Effects | Instant", BlueprintReadOnly, meta=(EditCondition="InstantEffectApplicationPolicy != EEffectApplicationPolicy::DoNotApply"))
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere, Category="Applied Effects | Duration", BlueprintReadOnly)
	EEffectApplicationPolicy DurationEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, Category="Applied Effects | Duration", BlueprintReadOnly, meta=(EditCondition="DurationEffectApplicationPolicy != EEffectApplicationPolicy::DoNotApply"))
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	UPROPERTY(EditAnywhere, Category="Applied Effects | Infinite", BlueprintReadOnly)
	EEffectApplicationPolicy InfiniteEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, Category="Applied Effects | Infinite", BlueprintReadOnly, meta=(EditCondition="InfiniteEffectApplicationPolicy != EEffectApplicationPolicy::DoNotApply"))
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

	UPROPERTY(EditAnywhere, Category="Applied Effects | Infinite", BlueprintReadOnly, meta=(EditCondition="InfiniteEffectApplicationPolicy != EEffectApplicationPolicy::DoNotApply"))
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy = EEffectRemovalPolicy::DoNotRemove;

private:

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveInfEffectHandles;
	
	
	
};
