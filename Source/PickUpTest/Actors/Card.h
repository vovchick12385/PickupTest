// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interface/Interactive.h"
#include "../Types.h"
#include "Card.generated.h"

class APickUpTestCharacter;


UCLASS()
class PICKUPTEST_API ACard : public AActor, public IInteractive
{
	GENERATED_BODY()
	
public:	
	ACard();

	virtual void Interact(APickUpTestCharacter* Character) override;

	virtual FName GetActionEventName()const override;

	UFUNCTION(BlueprintCallable)
	ECardType GetCard() const;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card Type")
	ECardType CardType = ECardType::None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Type")
	class UTexture* CardTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Type")
	class UStaticMeshComponent* CardMesh;
	
};
