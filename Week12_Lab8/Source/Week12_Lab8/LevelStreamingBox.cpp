// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelStreamingBox.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values
ALevelStreamingBox::ALevelStreamingBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OverlapVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapVolume"));
	RootComponent = OverlapVolume;
	OverlapVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ALevelStreamingBox::OverlapBegins);
	OverlapVolume->OnComponentEndOverlap.AddUniqueDynamic(this, &ALevelStreamingBox::OverlapEnds);

	LevelToLoad = "";

	
}

// Called when the game starts or when spawned
void ALevelStreamingBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALevelStreamingBox::OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);


	if (OtherActor == MyCharacter && LevelToLoad != "")
	{
		FLatentActionInfo LatentInfo;
		UGameplayStatics::LoadStreamLevel(this, LevelToLoad, true, true, LatentInfo);
	}
}

void ALevelStreamingBox::OverlapEnds(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	if (OtherActor == MyCharacter && LevelToLoad != "")
	{
		FLatentActionInfo LatentInfo;
		UGameplayStatics::UnloadStreamLevel(this, LevelToLoad, LatentInfo, false);
	}
}

// Called every frame
void ALevelStreamingBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

