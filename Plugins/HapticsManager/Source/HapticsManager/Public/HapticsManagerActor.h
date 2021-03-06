//Copyright bHaptics Inc. 2017

#pragma once

#include "Engine.h"
#include "HapticStructures.h"
#include "GameFramework/Actor.h"
#include "FeedbackFile.h"
#include "HapticsManagerActor.generated.h"


UCLASS()
class HAPTICSMANAGER_API AHapticsManagerActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHapticsManagerActor();

	TArray<FHapticFeedback> ChangedFeedbacks;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform & Transform) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	//Names of files currently loaded by the HapticsManager
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Haptics")
		TArray<FName> HapticFileNames;

	//Root folder storing the files saved in the HapticFileNames Array.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Haptics")
		FString HapticFileRootFolder;

	TArray<USceneComponent*> TactotFront;

	TArray<USceneComponent*> TactotBack;

	TArray<USceneComponent*> TactosyLeft;

	TArray<USceneComponent*> TactosyRight;

	TArray<USceneComponent*> Tactal;

	TArray<USceneComponent*> TactGloveLeft;

	TArray<USceneComponent*> TactGloveRight;

	TArray<USceneComponent*> TactShoeLeft;

	TArray<USceneComponent*> TactShoeRight;

	TArray<USceneComponent*> TactRacket;

	//Boolean to determine whether to load feedback files from the project's contents folder or the plugins directory.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Haptics")
		bool UseProjectFeedbackFolder = true;

	//Folder in the Contents directory to search for the haptic feedback files.
	//The full path is not needed, only its location relative to the Contents directory.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Haptics")
		FString ProjectFeedbackFolder = "HapticsManager/Feedback";

	//Submit a registered feedback using the file name as a key
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Submit Key",
			Keywords = "bHaptics",
			DeprecatedFunction,
			DeprecationMessage = "Function Deprecated. Please use SubmitFeedback in the HapticManagerComponent."),
		Category = "bHaptics")
		void SubmitKey(const FString &Key);

	//Submit a registered feedback using the file name as a key and a given RotationOption.
	//This call will only rotate vest feedback files, with other devices being kept the same.
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Submit Key with Transform",
			Keywords = "bHaptics",
			DeprecatedFunction,
			DeprecationMessage = "Function Deprecated. Please use SubmitFeedbackWithTransform in the HapticManagerComponent."),
		Category = "bHaptics")
		void SubmitKeyWithTransform(const FString &Key, const FString &AltKey, FRotationOption Option);

	//Submit a registered feedback using the file name as a key, and scale the intensity and duration by given ScaleOption.
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Submit Key with Scaled Intensity and Duration",
			Keywords = "bHaptics",
			DeprecatedFunction,
			DeprecationMessage = "Function Deprecated. Please use SubmitFeedbackWithIntensityDuration in the HapticManagerComponent."),
		Category = "bHaptics")
		void SubmitKeyWithIntensityDuration(const FString &Key, const FString &AltKey, FRotationOption RotationOption, FScaleOption ScaleOption);

	//Register a given feedback file.
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Register Feedback",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		void RegisterFeedbackFile(const FString &Key, UFeedbackFile* Feedback);

	//Submit a haptic feeback pattern to the given device using a byte array.
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Submit using Bytes",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		void SubmitBytes(const FString &key, EPosition PositionEnum, const TArray<uint8>& InputBytes, int32 DurationInMilliSecs);

	//Submit a haptic feeback pattern to the given device using the DotPoint structure.
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Submit using Dots",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		void SubmitDots(const FString &key, EPosition PositionEnum, const TArray<FDotPoint> DotPoints, int32 DurationInMilliSecs);

	//Submit a haptic feeback pattern to the given device using the PathPoint structure.
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Submit using Paths",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		void SubmitPath(const FString &key, EPosition PositionEnum, const TArray<FPathPoint>PathPoints, int32 DurationInMilliSecs);

	//Check if there is any feedback patterns currently playing on any device.
	UFUNCTION(BlueprintPure,
		meta = (DisplayName = "Is feedback currently playing",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		bool IsAnythingPlaying();

	//Is the specified feedback pattern currently playing
	UFUNCTION(BlueprintPure,
		meta = (DisplayName = "Is the feedback currently playing",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		bool IsRegisteredPlaying(const FString &Key);

	//Is the given device connected
	UFUNCTION(BlueprintPure,
		meta = (DisplayName = "Is the device connected",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		bool IsDeviceConnected(EPosition device);

	//Turn off all currently playing feedback patterns
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Turn off all feedback",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		void TurnOffAllFeedback();

	//Turn off the specified feedback pattern if it is playing;
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Turn off feedback",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		void TurnOffRegisteredFeedback(const FString &Key);

	//For use in the UI to set the dots used in visualisation.
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Set TactSuit Variables",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		void SetTactoSuit(USceneComponent* SleeveLeft, USceneComponent* SleeveRight, USceneComponent* Head, USceneComponent* VestFront, USceneComponent* VestBack,
			USceneComponent* GloveLeft, USceneComponent* GloveRight, USceneComponent* ShoeLeft, USceneComponent* ShoeRight, USceneComponent* Racket);

	//Enable haptic feedback
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Enable Feedback",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		void EnableFeedback();

	//Disable haptic feedback
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Disable Feedback",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		void DisableFeedback();

	//Toggle haptic feedback on/off
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Toggle Feedback",
			Keywords = "bHaptics"),
		Category = "bHaptics")
		void ToggleFeedback();


	//Submit a feedback file, and transform by a given RotationOption.
	//This call will only rotate vest feedback files, with other devices being kept the same.
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Submit Feedback with Transform",
			Keywords = "bHaptics"),
		Category = "bHaptics")
	void SubmitFeedbackWithTransform(UFeedbackFile* Feedback, const FString &AltKey, FRotationOption RotationOption);
	
	//Submit a feedback file, and scale the intensity and duration by the given ScaleOption.
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Submit Feedback with Scaled Intensity and Duration",
			Keywords = "bHaptics"),
		Category = "bHaptics")
	void SubmitFeedbackWithIntensityDuration(UFeedbackFile* Feedback, const FString &AltKey, FRotationOption RotationOption, FScaleOption ScaleOption);

	//Submit a feedback file
	UFUNCTION(BlueprintCallable,
		meta = (DisplayName = "Submit Feedback",
			Keywords = "bHaptics"),
		Category = "bHaptics")
	void SubmitFeedback(UFeedbackFile* Feedback);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Haptics")
	bool DisableFileLoad = false;

private:
	static FCriticalSection m_Mutex;
	//static bhaptics::PlayerResponse CurrentResponse;
	bool IsTicking = false;
	FString LoadFeedbackFiles(TArray<FString>& FilesOut);
	void Reset();
	void UpdateFeedback();
	void VisualiseFeedback(FHapticFeedback Feedback, TArray<USceneComponent*> TactoSuitItem);
	void InitialiseDots(TArray<USceneComponent*> TactoSuitItem);
	void RegisterFeeback(const FString &Key, const FString &FilePath);
	FString Id;
	bool IsInitialised = false;
	

};