// Fill out your copyright notice in the Description page of Project Settings.

#include "Skater_Pawn.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASkater_Pawn::ASkater_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASkater_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASkater_Pawn::Move(const FInputActionValue& Value)
{
	float MovementValue = Value.Get<float>();
	if (AccelerationCooldown > 0 || !GetCharacterMovement()->IsMovingOnGround()) return; // Paddle to accelerate. Cannot accel on air
	if (MovementValue < 0) //Reduce the speed of the skate if pressing backwards instead of going backwards.
	{
		GetCharacterMovement()->Velocity *= DecelerationSpeed;
		AccelerationCooldown = AccelerationInterval / 5; //Make the stop gradual using 1/5th of the cooldown
		return;
	}
	AccelerationCooldown = AccelerationInterval;
	DoAcceleration(MovementValue);
}

void ASkater_Pawn::Turn(const FInputActionValue& Value)
{
	if (!GetCharacterMovement()->IsMovingOnGround()) return; //Cannot air strafe
	float TurnValue = Value.Get<float>();
	DoRotation(TurnValue);
}

void ASkater_Pawn::RotateCamera(const FInputActionValue& Value)
{
}

// Called every frame
void ASkater_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (AccelerationCooldown > 0) AccelerationCooldown -= DeltaTime;
}

// Called to bind functionality to input
void ASkater_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ASkater_Pawn::Jump);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASkater_Pawn::Move);
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ASkater_Pawn::Turn);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ASkater_Pawn::RotateCamera);
	}
	else
	{
		UE_LOG(LogEngine, Error, TEXT("'%s' Failed to find an Enhanced Input component!"), *GetNameSafe(this));
	}
}

void ASkater_Pawn::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
}

void ASkater_Pawn::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
}

void ASkater_Pawn::DoAcceleration(float Forward)
{
	UE_LOG(LogEngine, Log, TEXT("DoAcceleration forward: %f"), Forward);
	GetCharacterMovement()->AddImpulse(GetActorForwardVector()*Forward*Acceleration, true);
}

void ASkater_Pawn::DoRotation(float Right)
{
	AddActorLocalRotation(FRotator(0,Right*TurnSpeed,0));
	float velocityMagnitude = GetCharacterMovement()->Velocity.Length();
	//Make sure that the character is always moving towards the facing direction
	GetCharacterMovement()->Velocity = GetActorForwardVector() * velocityMagnitude; 
}

void ASkater_Pawn::DoRailGrind()
{
}


