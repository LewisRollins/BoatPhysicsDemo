// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "SunseekerPath.generated.h"

UCLASS()
class METAVERSEVRTESTDEMO_API ASunseekerPath : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASunseekerPath();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spline")
	USplineComponent* SplineComponent; // Spline component to define the path

	// Function to generate a curved loop
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Spline")
	void GenerateCurvedLoop();

	// Editable properties for loop generation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
	float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
	int32 NumPoints;

};
