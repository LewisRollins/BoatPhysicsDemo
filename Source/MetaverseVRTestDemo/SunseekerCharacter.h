// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SplineComponent.h" // Include for spline component
#include "SunseekerPath.h"
#include "SunseekerCharacter.generated.h"

UCLASS()
class METAVERSEVRTESTDEMO_API ASunseekerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASunseekerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	 
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* BoatMesh; // Static mesh component for boat

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spline")
	TSubclassOf<ASunseekerPath> SplineActorClass; // Class of the spline actor to spawn

	ASunseekerPath* SpawnedSplineActor; // Instance of the spawned spline actor

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
	ASunseekerPath* AssignedSplineActor; // Reference to the spline actor assigned in the editor

	UFUNCTION(BlueprintCallable, Category = "Spline")
	void SpawnSplineActor(); // Function to spawn the spline actor in the editor

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spline")
	float MovementSpeed = 500.0f; // Speed at which the character moves along the spline

	float TargetDistanceAlongSpline; // Distance along the spline to move
	FVector TargetLocation; // Target location on the spline
};

