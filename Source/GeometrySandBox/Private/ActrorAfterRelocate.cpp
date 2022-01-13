// Fill out your copyright notice in the Description page of Project Settings.


#include "ActrorAfterRelocate.h"

// Sets default values
AActrorAfterRelocate::AActrorAfterRelocate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActrorAfterRelocate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActrorAfterRelocate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

