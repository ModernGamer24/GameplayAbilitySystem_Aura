// Aura learning project. xModern 2024

#pragma once

#include "CoreMinimal.h"



#define PRINT(Msg)\
{\
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, Msg);\
	UE_LOG(LogTemp, Display, TEXT(Msg))\
}


#define CUSTOM_DEPTH_RED 250


