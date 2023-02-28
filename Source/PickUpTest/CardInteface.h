// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CardInteface.generated.h"


class ACard;

UINTERFACE(MinimalAPI)
class UCardInteface : public UInterface
{
	GENERATED_BODY()
};


class PICKUPTEST_API ICardInteface
{
	GENERATED_BODY()

public:
	virtual bool UseCard(ACard* Card) const  PURE_VIRTUAL(ICardInterface::UseCard, return false;);
};
