// Copyright Kevin Taylor 2016

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

	void CloseDoor();
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
private:

	//specify a property to set how far the door opens
	//The UPROPERTY(VisibleAnywhere) allows this property to be visible in both blueprints and C++
	//UPROPERTY(VisibleAnywhere)
	//float OpenAngle = 90.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpens;		//Pawn inherits from actor

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.3f;

	float LastDoorOpenTime = 0.0f;
	
};
