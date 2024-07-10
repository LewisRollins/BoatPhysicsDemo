// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PowerboatCharacter.generated.h"

UCLASS()
class METAVERSEVRTESTDEMO_API APowerboatCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APowerboatCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Expose the static mesh component for blueprint editing
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* BoatMesh; // Static mesh component for boat

private:
	void MoveForward(float Value);
	void Turn(float Value);

public:
	// Rotation rate variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	float MaxTurnRate = 35.0f; // Maximum turn rate in degrees per second

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	float LerpSpeed = 1.0f; // Speed of lerping, adjust as needed

private:
	float CurrentRotationRate = 0.0f; // Current rotation rate

};
