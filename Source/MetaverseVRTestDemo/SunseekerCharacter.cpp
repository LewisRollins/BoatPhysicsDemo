// Fill out your copyright notice in the Description page of Project Settings.


#include "SunseekerCharacter.h"

// Sets default values
ASunseekerCharacter::ASunseekerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the static mesh component for the boat
	BoatMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoatMesh"));
	BoatMesh->SetupAttachment(RootComponent); // Attach to the root component or wherever appropriate

    // Initialize default values
    TargetDistanceAlongSpline = 0.0f;

    // Set the class to spawn (ensure this is a valid class)
    SplineActorClass = ASunseekerPath::StaticClass();
}

// Called when the game starts or when spawned
void ASunseekerCharacter::BeginPlay()
{
	Super::BeginPlay();

    if (AssignedSplineActor)
    {
        // Get the initial target location on the spline
        TargetLocation = AssignedSplineActor->SplineComponent->GetLocationAtDistanceAlongSpline(TargetDistanceAlongSpline, ESplineCoordinateSpace::World);
    }
}
	

// Called every frame
void ASunseekerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (AssignedSplineActor)
    {
        // Update the target distance along the spline
        TargetDistanceAlongSpline += MovementSpeed * DeltaTime;

        // Get the target location and tangent on the spline
        FVector NewLocation = AssignedSplineActor->SplineComponent->GetLocationAtDistanceAlongSpline(TargetDistanceAlongSpline, ESplineCoordinateSpace::World);
        FVector Tangent = AssignedSplineActor->SplineComponent->GetTangentAtDistanceAlongSpline(TargetDistanceAlongSpline, ESplineCoordinateSpace::World);

        // Set the boat's location to the target location
        SetActorLocation(NewLocation);

        // Calculate the new rotation based on the tangent
        FRotator NewRotation = Tangent.Rotation();
        SetActorRotation(NewRotation);
    }
}

void ASunseekerCharacter::SpawnSplineActor()
{
    // Ensure the SplineActorClass is set
    if (!SplineActorClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("SplineActorClass is not set in %s"), *GetName());
        return;
    }

    // Spawn the spline actor if not already spawned
    if (!SpawnedSplineActor)
    {
        SpawnedSplineActor = GetWorld()->SpawnActor<ASunseekerPath>(SplineActorClass, GetActorTransform());
        if (SpawnedSplineActor)
        {
            // Assign the spawned spline actor to the AssignedSplineActor property
            AssignedSplineActor = SpawnedSplineActor;

            // Get the initial target location on the spline
            TargetLocation = SpawnedSplineActor->SplineComponent->GetLocationAtDistanceAlongSpline(TargetDistanceAlongSpline, ESplineCoordinateSpace::World);
        }
    }
}

// Called to bind functionality to input
void ASunseekerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

