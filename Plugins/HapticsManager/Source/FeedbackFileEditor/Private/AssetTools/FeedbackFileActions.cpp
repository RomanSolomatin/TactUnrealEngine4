// Fill out your copyright notice in the Description page of Project Settings.

#include "FeedbackFileEditor.h"
#include "FeedbackFileActions.h"

#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "FeedbackFile.h"
#include "AllowWindowsPlatformTypes.h"
#include "HapticsManager/Private/SDK/hapticsManager.hpp"
#include "HideWindowsPlatformTypes.h"
#include "Styling/SlateStyle.h"


//#include "TextAssetEditorToolkit.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

FFeedbackFileActions::FFeedbackFileActions(const TSharedRef<FSlateStyleSet>& InStyle)
	: Style(InStyle)
{
}

bool FFeedbackFileActions::CanFilter()
{
	return true;
}

void FFeedbackFileActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder & MenuBuilder)
{
	/*FAssetTypeActions_Base::GetActions(InObjects, MenuBuilder);

	auto FeedbackFiles = GetTypedWeakObjectPtrs<UFeedbackFile>(InObjects);

	MenuBuilder.AddMenuEntry(
		LOCTEXT("FeedbackFile_PlayFeedback", "Play Feedback"),
		LOCTEXT("FeedbackFile_PlayFeedbackToolTip", "Play the selected feedback. Game must be running or simulated."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateLambda([=] {
		for (auto& FeedbackFile : FeedbackFiles)
		{
			if (FeedbackFile.IsValid())
			{
				std::string StandardKey(TCHAR_TO_UTF8(*FeedbackFile->Key));
				if (!bhaptics::HapticPlayer::instance()->isFeedbackRegistered(StandardKey))
				{
					TSharedPtr<FJsonObject> JsonProject = MakeShareable(new FJsonObject);
					TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(FeedbackFile->ProjectString);

					if (FJsonSerializer::Deserialize(Reader, JsonProject))
					{
						bhaptics::HapticPlayer::instance()->registerFeedback(StandardKey, JsonProject);
					}
				}
				bhaptics::HapticPlayer::instance()->submitRegistered(StandardKey);
			}
		}
	}),
			FCanExecuteAction::CreateLambda([=] {
		for (auto& FeedbackFile : FeedbackFiles)
		{
			if (FeedbackFile.IsValid())
			{
				return true;
			}
		}
		return false;
	})
		)
	);*/
}

uint32 FFeedbackFileActions::GetCategories()
{
	return EAssetTypeCategories::None;
}

FText FFeedbackFileActions::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_FeedbackFile", "Feedback File");
}

UClass * FFeedbackFileActions::GetSupportedClass() const
{
	return UFeedbackFile::StaticClass();
}

FColor FFeedbackFileActions::GetTypeColor() const
{
	return FColor::Silver;
}

bool FFeedbackFileActions::HasActions(const TArray<UObject*>& InObjects) const
{
	return false;
}

#undef LOCTEXT_NAMESPACE
