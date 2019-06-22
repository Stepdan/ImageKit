#pragma once

#include "src/Application/ImageKitCore/Interfaces/IImageKitCore.h"

#include "src/Application/ImageKitCore/Undo/UndoManager.h"

using namespace ImageKitCore::Interfaces;

namespace ImageKitCore {

class ImageKitCore : virtual public IImageKitCore
{
	friend class ImageKitCoreDeleter;
	friend std::shared_ptr<IImageKitCore> IImageKitCore::Create();

private:
	ImageKitCore();
	~ImageKitCore();
	ImageKitCore(const ImageKitCore &) = delete;
	ImageKitCore& operator=(const ImageKitCore &) = delete;

public:
	IImageKitEffectApplier& GetEffectApplierEngine() override;
	IImageKitIO& GetIOEngine() override;
	IImageKitUndo& GetUndoEngine() override;

	const std::shared_ptr<Core::Interfaces::IDataImage> & GetDataImage() const;

public:
	void ApplyEffect(const Proc::SettingsEffectBase & settingsBase, InputType type) override;
	void ApplyEffect(const std::shared_ptr<Proc::Interfaces::IEffectOneInput> & effect) override;
	void ApplyEffect(const std::shared_ptr<Proc::Interfaces::IEffectTwoInput> & effect) override;
	void ApplyEffect(const std::shared_ptr<Proc::Interfaces::IEffectVarInput> & effect) override;

public:
	void Load(const std::string & path) override;
	void Save(const std::string & path) const override;
	const std::string & GetSessionTempDir() const noexcept override;

public:
	void Push() override;
	void Undo() override;
	void Redo() override;
	void Reset() override;

private:
	std::shared_ptr<IDataImage> m_dataImage;

	std::string m_tempDir;

	std::unique_ptr<UndoManager> m_undoManager;

};

class ImageKitCoreDeleter
{
public:
	void operator()(ImageKitCore* obj) { delete obj; }
};

}
