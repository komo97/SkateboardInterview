// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "Skater_Pawn.generated.h"

UCLASS()
class SKATEBOARDINTERVIEW_API ASkater_Pawn : public ACharacter
{
	GENERATED_BODY()

protected:
	//Acceleration per tick while paddling
	UPROPERTY(EditAnywhere)
	float Acceleration = 1500.0f;
	//Permanent deceleration of the skate
	UPROPERTY(EditAnywhere)
	float DecelerationSpeed = 0.5f;
	//Turning speed of the skate
	UPROPERTY(EditAnywhere)
	float TurnSpeed = 0.3f;
	UPROPERTY(EditAnywhere)
	float AccelerationInterval = 1.0f;

	//Animation helper properties
	UPROPERTY(BlueprintReadOnly)
	bool bIsPaddling = false;
	UPROPERTY(BlueprintReadOnly)
	bool bIsJumping = false;
	
	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* TurnAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MouseLookAction;

private:
	enum class EMovementState
	{
		Grounded,
		Jumping,
		Falling,
		Grinding
	} CurrentMovementState = EMovementState::Grounded;
	
	float AccelerationCooldown = 0;
	
public:
	// Sets default values for this pawn's properties
	ASkater_Pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);
	void Turn(const FInputActionValue& Value);
	void RotateCamera(const FInputActionValue& Value);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

private:
	void DoAcceleration(float Forward);
	void FinishAcceleration();
	void DoJump();
	void DoRotation(float Right);
	void DoRailGrind(); //Might not implement
};
