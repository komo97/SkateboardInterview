// Fill out your copyright notice in the Description page of Project Settings.


#include "Skating_GameMode.h"

void ASkating_GameMode::AddPoints(int Multiplier)
{
	IPoints += 100 * Multiplier;
}
