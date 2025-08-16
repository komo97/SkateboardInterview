// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Skating_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class SKATEBOARDINTERVIEW_API ASkating_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	
public:
    UPROPERTY(BlueprintReadWrite)
    int IPoints = 0;
	
	UFUNCTION(BlueprintCallable)
	void AddPoints(int Multiplier = 1);
};
