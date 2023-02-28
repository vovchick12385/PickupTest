// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactive.generated.h"

class APickUpTestCharacter;

UINTERFACE(MinimalAPI)
class UInteractive : public UInterface
{
	GENERATED_BODY()
};


class PICKUPTEST_API IInteractive
{
	GENERATED_BODY()
public:
	virtual void Interact(APickUpTestCharacter* Character) PURE_VIRTUAL (IInteractive::Interact, );
	virtual FName GetActionEventName() const PURE_VIRTUAL(IInteractive::GetActionEventName, return FName(NAME_None););

};
