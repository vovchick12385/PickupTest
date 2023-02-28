// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EquippedCardComponent.generated.h"

class ACard;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PICKUPTEST_API UEquippedCardComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UEquippedCardComponent();

	ACard* GetCurrentCard(int num);

	void EquipCard(ACard* Card);
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Equipped Cards")
	TArray<ACard*> EquippedCards;
		
};
