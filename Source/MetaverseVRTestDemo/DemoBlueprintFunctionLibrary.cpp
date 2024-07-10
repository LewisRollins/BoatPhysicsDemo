// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoBlueprintFunctionLibrary.h"

float UDemoBlueprintFunctionLibrary::DistanceBetweenPoints(FVector PointA, FVector PointB)
{
    return FVector::Dist(PointA, PointB);
}
