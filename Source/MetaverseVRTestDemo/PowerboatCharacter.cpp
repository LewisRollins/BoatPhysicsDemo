// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerboatCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"

// Sets default values
APowerboatCharacter::APowerboatCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Create a spring arm component for the camera
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 300.0f;
    SpringArm->bUsePawnControlRotation = true;

    // Create a camera and attach it to the spring arm
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    // Create the static mesh component for the boat
    BoatMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoatMesh"));
    BoatMesh->SetupAttachment(RootComponent); // Attach to the root component or wherever appropriate

    // Set up character movement
    GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction of movement
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // Rotation rate (yaw)
    GetCharacterMovement()->MaxWalkSpeed = 1200.0f; // Adjust max speed as per your boat's requirements

}

// Called when the game starts or when spawned
void APowerboatCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerboatCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APowerboatCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind movement and rotation axis inputs
    PlayerInputComponent->BindAxis("MoveForward", this, &APowerboatCharacter::MoveForward);
    PlayerInputComponent->BindAxis("Turn", this, &APowerboatCharacter::Turn);

}

void APowerboatCharacter::MoveForward(float Value)
{
    // Move forward/backward based on input value
    if (Value != 0.0f)
    {
        AddMovementInput(GetActorForwardVector(), Value);
    }
}

void APowerboatCharacter::Turn(float Value)
{
    // Rotate left/right based on input value
    if (Value != 0.0f)
    {
        AddControllerYawInput(Value);
    }
}
