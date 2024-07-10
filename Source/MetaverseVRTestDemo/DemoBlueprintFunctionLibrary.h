// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DemoBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class METAVERSEVRTESTDEMO_API UDemoBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	static float DistanceBetweenPoints(FVector PointA, FVector PointB);
};
