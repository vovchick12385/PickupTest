// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interface/Interactive.h"
#include "Components/TimelineComponent.h"
#include "../Types.h"
#include "../CardInteface.h"
#include "Door.generated.h"

UCLASS()
class PICKUPTEST_API ADoor : public AActor, public IInteractive, public ICardInteface
{
	GENERATED_BODY()
public:
	ADoor();

	virtual void Interact(APickUpTestCharacter* Character) override;

	virtual FName GetActionEventName() const  override;

	virtual bool UseCard(ACard* Card) const  override;

	virtual void Tick(float DeltaTime) override;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactive| Door")
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactive| Door")
	USceneComponent* DoorPivot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactive| Door")
	float AngleCloused= 0.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactive| Door")
	float AngleOpened = 90.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Interactive| Door")
	UCurveFloat* DoorAnimatyionCurve;

	virtual void BeginPlay() override;

	UPROPERTY(EditDEfaultsOnly, BlueprintReadOnly, Category = "Door | Type")
	ECardType DoorType = ECardType::None;
private:
	FTimeline DoorOpenAnimTimeline;

	bool bIsOpen = false;

	UFUNCTION()
	void UpdateDoorAnimation(float Alpha);

	UFUNCTION()
	void OnDoorAnimatonFinished();

	void InteractWithDoor();

};
