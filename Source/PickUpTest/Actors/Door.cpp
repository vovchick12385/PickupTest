// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "../Types.h"
#include "Card.h"
#include "../PickUpTestCharacter.h"
#include "../ActorComponent/EquippedCardComponent.h"
#include <Kismet/KismetSystemLibrary.h>

ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	USceneComponent* DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DoorRoot"));
	SetRootComponent(DefaultRoot);
	DoorPivot = CreateDefaultSubobject<USceneComponent>(TEXT("DoorPivot"));
	DoorPivot->SetupAttachment(DefaultRoot);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(DoorPivot);
}

void ADoor::Interact(APickUpTestCharacter* Character)
{
	int num = Character->CurrentEquippedCard;
	if (UseCard(Character->Equipment->GetCurrentCard(num)))
	{
		InteractWithDoor();
	}
	else
	{
		UKismetSystemLibrary::PrintString(this, TEXT("the door does not support this card interface"));
	}
}

FName ADoor::GetActionEventName() const
{
	return ActionInteract;
}

bool ADoor::UseCard(ACard* Card) const
{
	if(Card->GetCard() == DoorType)
		return true;
	return false;
}

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DoorOpenAnimTimeline.TickTimeline(DeltaTime);
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(DoorAnimatyionCurve))
	{
		FOnTimelineFloatStatic DoorAnimationDelegate;
		DoorAnimationDelegate.BindUObject(this, &ADoor::UpdateDoorAnimation);
		DoorOpenAnimTimeline.AddInterpFloat(DoorAnimatyionCurve, DoorAnimationDelegate);
		FOnTimelineEventStatic DoorOpenDelegate;
		DoorOpenDelegate.BindUObject(this, &ADoor::OnDoorAnimatonFinished);
		DoorOpenAnimTimeline.SetTimelineFinishedFunc(DoorOpenDelegate);
	}
}

void ADoor::UpdateDoorAnimation(float Alpha)
{
	float YawAngle = FMath::Lerp(AngleCloused, AngleOpened, FMath::Clamp(Alpha,0.f, 1.f));
	DoorPivot->SetRelativeRotation(FRotator(0.f, YawAngle, 0.f));
}

void ADoor::OnDoorAnimatonFinished()
{
	SetActorTickEnabled(false);
}

void ADoor::InteractWithDoor()
{
	SetActorTickEnabled(true);
	if (bIsOpen)
	{
		DoorOpenAnimTimeline.Reverse();
	}
	else
	{
		DoorOpenAnimTimeline.Play();
	}
	bIsOpen = !bIsOpen;
}
