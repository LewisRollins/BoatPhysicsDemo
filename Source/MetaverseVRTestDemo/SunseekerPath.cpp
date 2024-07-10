// Fill out your copyright notice in the Description page of Project Settings.


#include "SunseekerPath.h"

// Sets default values
ASunseekerPath::ASunseekerPath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the spline component and set it as the root component of the actor
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	RootComponent = SplineComponent;

}

// Called when the game starts or when spawned
void ASunseekerPath::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void ASunseekerPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASunseekerPath::GenerateCurvedLoop()
{
    // Clear existing spline points
    SplineComponent->ClearSplinePoints();

    // Generate points in a circular loop
    for (int32 i = 0; i < NumPoints; ++i)
    {
        float Angle = (2.0f * PI * i) / NumPoints;
        FVector Location = FVector(Radius * FMath::Cos(Angle), Radius * FMath::Sin(Angle), 0.0f);

        // Add point to spline
        SplineComponent->AddSplinePoint(Location, ESplineCoordinateSpace::Local);
    }

    // Update the spline component
    SplineComponent->UpdateSpline();
}