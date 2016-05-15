// Copyright Kevin Taylor 2016

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}

void UOpenDoor::OpenDoor()
{
	//Assign a variable to the object owner(the door)
	AActor* Owner = GetOwner();

	//Create a Rotation to be applied to the objects transform rotation
	FRotator NewRotation = FRotator(0, -90.0f, 0);

	//Set the new rotation to the door/object
	Owner->SetActorRotation(NewRotation);
}

void UOpenDoor::CloseDoor()
{
	//Assign a variable to the object owner(the door)
	AActor* Owner = GetOwner();

	//Create a Rotation to be applied to the objects transform rotation
	FRotator NewRotation = FRotator(0, 90.0f, 0);

	//Set the new rotation to the door/object
	Owner->SetActorRotation(NewRotation);
}
// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	//Poll the trigger Volume Every Frame
	//If the ActorThatOpens is in the trigger volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		//Open Door
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	
	//Check if its time to close the door.
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay)
	{
		CloseDoor();
	}
}

