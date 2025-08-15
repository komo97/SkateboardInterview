// Fill out your copyright notice in the Description page of Project Settings.


#include "Skater_Pawn.h"

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
}

void ASkater_Pawn::Turn(const FInputActionValue& Value)
{
}

void ASkater_Pawn::RotateCamera(const FInputActionValue& Value)
{
}

// Called every frame
void ASkater_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASkater_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

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
}

void ASkater_Pawn::DoRotation(float Right)
{
}

void ASkater_Pawn::DoJump()
{
}

void ASkater_Pawn::DoRailGrind()
{
}

void ASkater_Pawn::DoMovement()
{
}

