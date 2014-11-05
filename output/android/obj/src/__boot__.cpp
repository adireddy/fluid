#include <hxcpp.h>

#include <openfl/utils/Endian.h>
#include <openfl/text/TextFieldType.h>
#include <openfl/text/TextFieldAutoSize.h>
#include <openfl/text/GridFitType.h>
#include <openfl/text/AntiAliasType.h>
#include <openfl/system/SecurityDomain.h>
#include <openfl/system/LoaderContext.h>
#include <openfl/system/ApplicationDomain.h>
#include <openfl/net/URLVariables.h>
#include <openfl/net/URLRequestHeader.h>
#include <openfl/net/URLLoaderDataFormat.h>
#include <openfl/media/SoundTransform.h>
#include <openfl/media/SoundLoaderContext.h>
#include <openfl/media/ID3Info.h>
#include <openfl/geom/Vector3D.h>
#include <openfl/geom/Orientation3D.h>
#include <openfl/geom/Matrix3D.h>
#include <openfl/events/UncaughtErrorEvents.h>
#include <openfl/events/UncaughtErrorEvent.h>
#include <openfl/events/SampleDataEvent.h>
#include <openfl/events/ProgressEvent.h>
#include <openfl/events/JoystickEvent.h>
#include <openfl/events/IOErrorEvent.h>
#include <openfl/events/FocusEvent.h>
#include <openfl/events/EventPhase.h>
#include <openfl/events/ErrorEvent.h>
#include <openfl/events/TextEvent.h>
#include <openfl/errors/RangeError.h>
#include <openfl/errors/EOFError.h>
#include <openfl/errors/ArgumentError.h>
#include <openfl/errors/Error.h>
#include <openfl/display/StageScaleMode.h>
#include <openfl/display/StageDisplayState.h>
#include <openfl/display/StageAlign.h>
#include <openfl/display/PixelSnapping.h>
#include <openfl/display/InterpolationMethod.h>
#include <openfl/display/GraphicsPathWinding.h>
#include <openfl/display/GradientType.h>
#include <openfl/display/FrameLabel.h>
#include <openfl/display/FPS.h>
#include <openfl/_v2/utils/WeakRef.h>
#include <openfl/_v2/utils/Float32Array.h>
#include <openfl/_v2/utils/CompressionAlgorithm.h>
#include <openfl/_v2/utils/ByteArray.h>
#include <openfl/_v2/utils/IDataInput.h>
#include <openfl/_v2/utils/IDataOutput.h>
#include <openfl/_v2/utils/ArrayBufferView.h>
#include <openfl/_v2/utils/IMemoryRange.h>
#include <openfl/_v2/ui/Keyboard.h>
#include <openfl/_v2/text/TextLineMetrics.h>
#include <openfl/_v2/text/TextFormat.h>
#include <openfl/_v2/text/FontType.h>
#include <openfl/_v2/text/FontStyle.h>
#include <openfl/_v2/text/Font.h>
#include <openfl/_v2/system/ScreenMode.h>
#include <openfl/_v2/system/PixelFormat.h>
#include <openfl/_v2/system/Capabilities.h>
#include <openfl/_v2/net/URLRequestMethod.h>
#include <openfl/_v2/net/URLRequest.h>
#include <openfl/_v2/media/AudioThreadState.h>
#include <openfl/_v2/media/SoundChannel.h>
#include <openfl/_v2/media/InternalAudioType.h>
#include <openfl/_v2/media/Sound.h>
#include <openfl/_v2/gl/GLTexture.h>
#include <openfl/_v2/gl/GLShader.h>
#include <openfl/_v2/gl/GLRenderbuffer.h>
#include <openfl/_v2/gl/GLProgram.h>
#include <openfl/_v2/gl/GLFramebuffer.h>
#include <openfl/_v2/gl/GLBuffer.h>
#include <openfl/_v2/gl/GLObject.h>
#include <openfl/_v2/gl/_GL/Float32Data_Impl_.h>
#include <openfl/_v2/gl/GL.h>
#include <openfl/_v2/geom/Transform.h>
#include <openfl/_v2/geom/Matrix.h>
#include <openfl/_v2/geom/ColorTransform.h>
#include <openfl/_v2/filters/BitmapFilter.h>
#include <openfl/_v2/events/SystemEvent.h>
#include <openfl/_v2/events/KeyboardEvent.h>
#include <openfl/_v2/events/HTTPStatusEvent.h>
#include <openfl/_v2/events/Listener.h>
#include <openfl/_v2/display/TriangleCulling.h>
#include <openfl/_v2/display/Tilesheet.h>
#include <openfl/_v2/geom/Point.h>
#include <openfl/_v2/display/StageQuality.h>
#include <openfl/_v2/display/TouchInfo.h>
#include <openfl/_v2/display/SpreadMethod.h>
#include <openfl/_v2/display/Shape.h>
#include <openfl/_v2/display/OpenGLView.h>
#include <openfl/_v2/display/MovieClip.h>
#include <openfl/_v2/display/ManagedStage.h>
#include <openfl/_v2/display/LoaderInfo.h>
#include <openfl/_v2/net/URLLoader.h>
#include <openfl/_v2/display/Loader.h>
#include <openfl/_v2/display/LineScaleMode.h>
#include <openfl/_v2/display/JointStyle.h>
#include <openfl/_v2/display/IGraphicsData.h>
#include <openfl/_v2/display/Graphics.h>
#include <openfl/_v2/display/DirectRenderer.h>
#include <openfl/_v2/display/CapsStyle.h>
#include <openfl/_v2/display/BlendMode.h>
#include <openfl/_v2/display/OptimizedPerlin.h>
#include <openfl/_v2/display/BitmapData.h>
#include <openfl/_v2/display/Bitmap.h>
#include <openfl/_v2/_Vector/Vector_Impl_.h>
#include <openfl/_v2/Memory.h>
#include <openfl/_v2/AssetType.h>
#include <openfl/_v2/AssetData.h>
#include <openfl/_v2/Assets.h>
#include <openfl/_v2/AssetCache.h>
#include <msignal/Slot2.h>
#include <msignal/Slot1.h>
#include <msignal/Slot0.h>
#include <msignal/Slot.h>
#include <msignal/Signal2.h>
#include <motion/easing/ExpoEaseInOut.h>
#include <motion/easing/ExpoEaseIn.h>
#include <motion/easing/CubicEaseOut.h>
#include <motion/easing/CubicEaseInOut.h>
#include <motion/easing/CubicEaseIn.h>
#include <motion/easing/Cubic.h>
#include <motion/actuators/TransformActuator.h>
#include <motion/actuators/PropertyPathDetails.h>
#include <motion/actuators/PropertyDetails.h>
#include <motion/actuators/MotionPathActuator.h>
#include <motion/actuators/MethodActuator.h>
#include <motion/actuators/FilterActuator.h>
#include <motion/RotationPath.h>
#include <motion/LinearPath.h>
#include <motion/BezierPath.h>
#include <motion/ComponentPath.h>
#include <motion/IComponentPath.h>
#include <motion/MotionPath.h>
#include <motion/_Actuate/TweenTimer.h>
#include <motion/_Actuate/TransformOptions.h>
#include <motion/_Actuate/EffectsOptions.h>
#include <motion/Actuate.h>
#include <motion/easing/ExpoEaseOut.h>
#include <motion/easing/IEasing.h>
#include <motion/easing/Expo.h>
#include <motion/actuators/SimpleActuator.h>
#include <motion/actuators/GenericActuator.h>
#include <motion/actuators/IGenericActuator.h>
#include <haxe/zip/Uncompress.h>
#include <haxe/zip/FlushMode.h>
#include <haxe/zip/Compress.h>
#include <haxe/io/Error.h>
#include <haxe/io/Eof.h>
#include <haxe/io/BytesBuffer.h>
#include <haxe/format/JsonParser.h>
#include <haxe/ds/StringMap.h>
#include <haxe/ds/ObjectMap.h>
#include <haxe/ds/IntMap.h>
#include <haxe/Unserializer.h>
#include <haxe/Timer.h>
#include <haxe/Resource.h>
#include <haxe/Log.h>
#include <haxe/CallStack.h>
#include <haxe/StackItem.h>
#include <fluid/text/FluidTextFormat.h>
#include <fluid/text/FluidText.h>
#include <openfl/_v2/text/TextField.h>
#include <fluid/geom/FluidRectangle.h>
#include <openfl/_v2/geom/Rectangle.h>
#include <fluid/events/EventData.h>
#include <fluid/display/FluidStage.h>
#include <openfl/_v2/display/Stage.h>
#include <openfl/_v2/events/TouchEvent.h>
#include <openfl/_v2/events/MouseEvent.h>
#include <openfl/_v2/events/Event.h>
#include <fluid/display/FluidGraphics.h>
#include <fluid/FluidAssets.h>
#include <cpp/vm/Thread.h>
#include <cpp/vm/Mutex.h>
#include <cpp/rtti/FieldNumericIntegerLookup.h>
#include <com/arm/demo/widgets/menu/PopoutMenu.h>
#include <com/arm/demo/widgets/menu/MenuItem.h>
#include <com/arm/demo/widgets/menu/Menu.h>
#include <com/arm/demo/widgets/Label.h>
#include <com/arm/demo/widgets/Button.h>
#include <com/arm/demo/notifications/internal/ViewStateNotification.h>
#include <com/arm/demo/notifications/internal/MenuNotification.h>
#include <msignal/Signal0.h>
#include <msignal/SlotList.h>
#include <msignal/Signal1.h>
#include <msignal/Signal.h>
#include <com/arm/demo/model/DemoModel.h>
#include <com/arm/demo/components/menu/MenuView.h>
#include <com/arm/demo/components/menu/MenuController.h>
#include <com/arm/demo/components/bunnymark/BunnymarkView.h>
#include <com/arm/demo/components/bunnymark/BunnymarkController.h>
#include <com/arm/demo/components/bunnymark/Bunny.h>
#include <fluid/display/FluidSprite.h>
#include <com/arm/demo/components/GameComponentView.h>
#include <com/arm/demo/view/DemoView.h>
#include <com/arm/demo/components/GameComponentController.h>
#include <com/arm/demo/controller/DemoController.h>
#include <com/arm/demo/comms/DemoCommsController.h>
#include <Type.h>
#include <StringTools.h>
#include <StringBuf.h>
#include <Reflect.h>
#include <IMap.h>
#include <List.h>
#include <Lambda.h>
#include <DefaultAssetLibrary.h>
#include <openfl/_v2/AssetLibrary.h>
#include <Date.h>
#include <DocumentClass.h>
#include <com/arm/demo/Main.h>
#include <com/arm/demo/Application.h>
#include <fluid/Fluid.h>
#include <openfl/_v2/display/Sprite.h>
#include <openfl/_v2/display/DisplayObjectContainer.h>
#include <openfl/_v2/display/InteractiveObject.h>
#include <openfl/_v2/display/DisplayObject.h>
#include <openfl/_v2/Lib.h>
#include <Std.h>
#include <sys/io/_Process/Stdout.h>
#include <haxe/io/Input.h>
#include <haxe/io/Bytes.h>
#include <sys/io/_Process/Stdin.h>
#include <haxe/io/Output.h>
#include <sys/io/Process.h>
#include <Sys.h>
#include <cpp/Lib.h>
#include <openfl/_v2/display/IBitmapDrawable.h>
#include <openfl/_v2/events/EventDispatcher.h>
#include <openfl/_v2/events/IEventDispatcher.h>
#include <ApplicationMain.h>

void __files__boot();

void __boot_all()
{
__files__boot();
hx::RegisterResources( hx::GetResources() );
::openfl::utils::Endian_obj::__register();
::openfl::text::TextFieldType_obj::__register();
::openfl::text::TextFieldAutoSize_obj::__register();
::openfl::text::GridFitType_obj::__register();
::openfl::text::AntiAliasType_obj::__register();
::openfl::system::SecurityDomain_obj::__register();
::openfl::system::LoaderContext_obj::__register();
::openfl::system::ApplicationDomain_obj::__register();
::openfl::net::URLVariables_obj::__register();
::openfl::net::URLRequestHeader_obj::__register();
::openfl::net::URLLoaderDataFormat_obj::__register();
::openfl::media::SoundTransform_obj::__register();
::openfl::media::SoundLoaderContext_obj::__register();
::openfl::media::ID3Info_obj::__register();
::openfl::geom::Vector3D_obj::__register();
::openfl::geom::Orientation3D_obj::__register();
::openfl::geom::Matrix3D_obj::__register();
::openfl::events::UncaughtErrorEvents_obj::__register();
::openfl::events::UncaughtErrorEvent_obj::__register();
::openfl::events::SampleDataEvent_obj::__register();
::openfl::events::ProgressEvent_obj::__register();
::openfl::events::JoystickEvent_obj::__register();
::openfl::events::IOErrorEvent_obj::__register();
::openfl::events::FocusEvent_obj::__register();
::openfl::events::EventPhase_obj::__register();
::openfl::events::ErrorEvent_obj::__register();
::openfl::events::TextEvent_obj::__register();
::openfl::errors::RangeError_obj::__register();
::openfl::errors::EOFError_obj::__register();
::openfl::errors::ArgumentError_obj::__register();
::openfl::errors::Error_obj::__register();
::openfl::display::StageScaleMode_obj::__register();
::openfl::display::StageDisplayState_obj::__register();
::openfl::display::StageAlign_obj::__register();
::openfl::display::PixelSnapping_obj::__register();
::openfl::display::InterpolationMethod_obj::__register();
::openfl::display::GraphicsPathWinding_obj::__register();
::openfl::display::GradientType_obj::__register();
::openfl::display::FrameLabel_obj::__register();
::openfl::display::FPS_obj::__register();
::openfl::_v2::utils::WeakRef_obj::__register();
::openfl::_v2::utils::Float32Array_obj::__register();
::openfl::_v2::utils::CompressionAlgorithm_obj::__register();
::openfl::_v2::utils::ByteArray_obj::__register();
::openfl::_v2::utils::IDataInput_obj::__register();
::openfl::_v2::utils::IDataOutput_obj::__register();
::openfl::_v2::utils::ArrayBufferView_obj::__register();
::openfl::_v2::utils::IMemoryRange_obj::__register();
::openfl::_v2::ui::Keyboard_obj::__register();
::openfl::_v2::text::TextLineMetrics_obj::__register();
::openfl::_v2::text::TextFormat_obj::__register();
::openfl::_v2::text::FontType_obj::__register();
::openfl::_v2::text::FontStyle_obj::__register();
::openfl::_v2::text::Font_obj::__register();
::openfl::_v2::system::ScreenMode_obj::__register();
::openfl::_v2::system::PixelFormat_obj::__register();
::openfl::_v2::system::Capabilities_obj::__register();
::openfl::_v2::net::URLRequestMethod_obj::__register();
::openfl::_v2::net::URLRequest_obj::__register();
::openfl::_v2::media::AudioThreadState_obj::__register();
::openfl::_v2::media::SoundChannel_obj::__register();
::openfl::_v2::media::InternalAudioType_obj::__register();
::openfl::_v2::media::Sound_obj::__register();
::openfl::_v2::gl::GLTexture_obj::__register();
::openfl::_v2::gl::GLShader_obj::__register();
::openfl::_v2::gl::GLRenderbuffer_obj::__register();
::openfl::_v2::gl::GLProgram_obj::__register();
::openfl::_v2::gl::GLFramebuffer_obj::__register();
::openfl::_v2::gl::GLBuffer_obj::__register();
::openfl::_v2::gl::GLObject_obj::__register();
::openfl::_v2::gl::_GL::Float32Data_Impl__obj::__register();
::openfl::_v2::gl::GL_obj::__register();
::openfl::_v2::geom::Transform_obj::__register();
::openfl::_v2::geom::Matrix_obj::__register();
::openfl::_v2::geom::ColorTransform_obj::__register();
::openfl::_v2::filters::BitmapFilter_obj::__register();
::openfl::_v2::events::SystemEvent_obj::__register();
::openfl::_v2::events::KeyboardEvent_obj::__register();
::openfl::_v2::events::HTTPStatusEvent_obj::__register();
::openfl::_v2::events::Listener_obj::__register();
::openfl::_v2::display::TriangleCulling_obj::__register();
::openfl::_v2::display::Tilesheet_obj::__register();
::openfl::_v2::geom::Point_obj::__register();
::openfl::_v2::display::StageQuality_obj::__register();
::openfl::_v2::display::TouchInfo_obj::__register();
::openfl::_v2::display::SpreadMethod_obj::__register();
::openfl::_v2::display::Shape_obj::__register();
::openfl::_v2::display::OpenGLView_obj::__register();
::openfl::_v2::display::MovieClip_obj::__register();
::openfl::_v2::display::ManagedStage_obj::__register();
::openfl::_v2::display::LoaderInfo_obj::__register();
::openfl::_v2::net::URLLoader_obj::__register();
::openfl::_v2::display::Loader_obj::__register();
::openfl::_v2::display::LineScaleMode_obj::__register();
::openfl::_v2::display::JointStyle_obj::__register();
::openfl::_v2::display::IGraphicsData_obj::__register();
::openfl::_v2::display::Graphics_obj::__register();
::openfl::_v2::display::DirectRenderer_obj::__register();
::openfl::_v2::display::CapsStyle_obj::__register();
::openfl::_v2::display::BlendMode_obj::__register();
::openfl::_v2::display::OptimizedPerlin_obj::__register();
::openfl::_v2::display::BitmapData_obj::__register();
::openfl::_v2::display::Bitmap_obj::__register();
::openfl::_v2::_Vector::Vector_Impl__obj::__register();
::openfl::_v2::Memory_obj::__register();
::openfl::_v2::AssetType_obj::__register();
::openfl::_v2::AssetData_obj::__register();
::openfl::_v2::Assets_obj::__register();
::openfl::_v2::AssetCache_obj::__register();
::msignal::Slot2_obj::__register();
::msignal::Slot1_obj::__register();
::msignal::Slot0_obj::__register();
::msignal::Slot_obj::__register();
::msignal::Signal2_obj::__register();
::motion::easing::ExpoEaseInOut_obj::__register();
::motion::easing::ExpoEaseIn_obj::__register();
::motion::easing::CubicEaseOut_obj::__register();
::motion::easing::CubicEaseInOut_obj::__register();
::motion::easing::CubicEaseIn_obj::__register();
::motion::easing::Cubic_obj::__register();
::motion::actuators::TransformActuator_obj::__register();
::motion::actuators::PropertyPathDetails_obj::__register();
::motion::actuators::PropertyDetails_obj::__register();
::motion::actuators::MotionPathActuator_obj::__register();
::motion::actuators::MethodActuator_obj::__register();
::motion::actuators::FilterActuator_obj::__register();
::motion::RotationPath_obj::__register();
::motion::LinearPath_obj::__register();
::motion::BezierPath_obj::__register();
::motion::ComponentPath_obj::__register();
::motion::IComponentPath_obj::__register();
::motion::MotionPath_obj::__register();
::motion::_Actuate::TweenTimer_obj::__register();
::motion::_Actuate::TransformOptions_obj::__register();
::motion::_Actuate::EffectsOptions_obj::__register();
::motion::Actuate_obj::__register();
::motion::easing::ExpoEaseOut_obj::__register();
::motion::easing::IEasing_obj::__register();
::motion::easing::Expo_obj::__register();
::motion::actuators::SimpleActuator_obj::__register();
::motion::actuators::GenericActuator_obj::__register();
::motion::actuators::IGenericActuator_obj::__register();
::haxe::zip::Uncompress_obj::__register();
::haxe::zip::FlushMode_obj::__register();
::haxe::zip::Compress_obj::__register();
::haxe::io::Error_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::haxe::format::JsonParser_obj::__register();
::haxe::ds::StringMap_obj::__register();
::haxe::ds::ObjectMap_obj::__register();
::haxe::ds::IntMap_obj::__register();
::haxe::Unserializer_obj::__register();
::haxe::Timer_obj::__register();
::haxe::Resource_obj::__register();
::haxe::Log_obj::__register();
::haxe::CallStack_obj::__register();
::haxe::StackItem_obj::__register();
::fluid::text::FluidTextFormat_obj::__register();
::fluid::text::FluidText_obj::__register();
::openfl::_v2::text::TextField_obj::__register();
::fluid::geom::FluidRectangle_obj::__register();
::openfl::_v2::geom::Rectangle_obj::__register();
::fluid::events::EventData_obj::__register();
::fluid::display::FluidStage_obj::__register();
::openfl::_v2::display::Stage_obj::__register();
::openfl::_v2::events::TouchEvent_obj::__register();
::openfl::_v2::events::MouseEvent_obj::__register();
::openfl::_v2::events::Event_obj::__register();
::fluid::display::FluidGraphics_obj::__register();
::fluid::FluidAssets_obj::__register();
::cpp::vm::Thread_obj::__register();
::cpp::vm::Mutex_obj::__register();
::cpp::rtti::FieldNumericIntegerLookup_obj::__register();
::com::arm::demo::widgets::menu::PopoutMenu_obj::__register();
::com::arm::demo::widgets::menu::MenuItem_obj::__register();
::com::arm::demo::widgets::menu::Menu_obj::__register();
::com::arm::demo::widgets::Label_obj::__register();
::com::arm::demo::widgets::Button_obj::__register();
::com::arm::demo::notifications::internal::ViewStateNotification_obj::__register();
::com::arm::demo::notifications::internal::MenuNotification_obj::__register();
::msignal::Signal0_obj::__register();
::msignal::SlotList_obj::__register();
::msignal::Signal1_obj::__register();
::msignal::Signal_obj::__register();
::com::arm::demo::model::DemoModel_obj::__register();
::com::arm::demo::components::menu::MenuView_obj::__register();
::com::arm::demo::components::menu::MenuController_obj::__register();
::com::arm::demo::components::bunnymark::BunnymarkView_obj::__register();
::com::arm::demo::components::bunnymark::BunnymarkController_obj::__register();
::com::arm::demo::components::bunnymark::Bunny_obj::__register();
::fluid::display::FluidSprite_obj::__register();
::com::arm::demo::components::GameComponentView_obj::__register();
::com::arm::demo::view::DemoView_obj::__register();
::com::arm::demo::components::GameComponentController_obj::__register();
::com::arm::demo::controller::DemoController_obj::__register();
::com::arm::demo::comms::DemoCommsController_obj::__register();
::Type_obj::__register();
::StringTools_obj::__register();
::StringBuf_obj::__register();
::Reflect_obj::__register();
::IMap_obj::__register();
::List_obj::__register();
::Lambda_obj::__register();
::DefaultAssetLibrary_obj::__register();
::openfl::_v2::AssetLibrary_obj::__register();
::Date_obj::__register();
::DocumentClass_obj::__register();
::com::arm::demo::Main_obj::__register();
::com::arm::demo::Application_obj::__register();
::fluid::Fluid_obj::__register();
::openfl::_v2::display::Sprite_obj::__register();
::openfl::_v2::display::DisplayObjectContainer_obj::__register();
::openfl::_v2::display::InteractiveObject_obj::__register();
::openfl::_v2::display::DisplayObject_obj::__register();
::openfl::_v2::Lib_obj::__register();
::Std_obj::__register();
::sys::io::_Process::Stdout_obj::__register();
::haxe::io::Input_obj::__register();
::haxe::io::Bytes_obj::__register();
::sys::io::_Process::Stdin_obj::__register();
::haxe::io::Output_obj::__register();
::sys::io::Process_obj::__register();
::Sys_obj::__register();
::cpp::Lib_obj::__register();
::openfl::_v2::display::IBitmapDrawable_obj::__register();
::openfl::_v2::events::EventDispatcher_obj::__register();
::openfl::_v2::events::IEventDispatcher_obj::__register();
::ApplicationMain_obj::__register();
::msignal::SlotList_obj::__init__();
::openfl::_v2::utils::ByteArray_obj::__init__();
::cpp::Lib_obj::__boot();
::cpp::rtti::FieldNumericIntegerLookup_obj::__boot();
::cpp::vm::Mutex_obj::__boot();
::cpp::vm::Thread_obj::__boot();
::haxe::Log_obj::__boot();
::ApplicationMain_obj::__boot();
::openfl::_v2::events::IEventDispatcher_obj::__boot();
::openfl::_v2::events::EventDispatcher_obj::__boot();
::openfl::_v2::display::IBitmapDrawable_obj::__boot();
::Sys_obj::__boot();
::sys::io::Process_obj::__boot();
::haxe::io::Output_obj::__boot();
::sys::io::_Process::Stdin_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::haxe::io::Input_obj::__boot();
::sys::io::_Process::Stdout_obj::__boot();
::Std_obj::__boot();
::openfl::_v2::Lib_obj::__boot();
::openfl::_v2::display::DisplayObject_obj::__boot();
::openfl::_v2::display::InteractiveObject_obj::__boot();
::openfl::_v2::display::DisplayObjectContainer_obj::__boot();
::openfl::_v2::display::Sprite_obj::__boot();
::fluid::Fluid_obj::__boot();
::com::arm::demo::Application_obj::__boot();
::com::arm::demo::Main_obj::__boot();
::DocumentClass_obj::__boot();
::Date_obj::__boot();
::openfl::_v2::AssetLibrary_obj::__boot();
::DefaultAssetLibrary_obj::__boot();
::Lambda_obj::__boot();
::List_obj::__boot();
::IMap_obj::__boot();
::Reflect_obj::__boot();
::StringBuf_obj::__boot();
::StringTools_obj::__boot();
::Type_obj::__boot();
::com::arm::demo::comms::DemoCommsController_obj::__boot();
::com::arm::demo::controller::DemoController_obj::__boot();
::com::arm::demo::components::GameComponentController_obj::__boot();
::com::arm::demo::view::DemoView_obj::__boot();
::com::arm::demo::components::GameComponentView_obj::__boot();
::fluid::display::FluidSprite_obj::__boot();
::com::arm::demo::components::bunnymark::Bunny_obj::__boot();
::com::arm::demo::components::bunnymark::BunnymarkController_obj::__boot();
::com::arm::demo::components::bunnymark::BunnymarkView_obj::__boot();
::com::arm::demo::components::menu::MenuController_obj::__boot();
::com::arm::demo::components::menu::MenuView_obj::__boot();
::com::arm::demo::model::DemoModel_obj::__boot();
::msignal::Signal_obj::__boot();
::msignal::Signal1_obj::__boot();
::msignal::SlotList_obj::__boot();
::msignal::Signal0_obj::__boot();
::com::arm::demo::notifications::internal::MenuNotification_obj::__boot();
::com::arm::demo::notifications::internal::ViewStateNotification_obj::__boot();
::com::arm::demo::widgets::Button_obj::__boot();
::com::arm::demo::widgets::Label_obj::__boot();
::com::arm::demo::widgets::menu::Menu_obj::__boot();
::com::arm::demo::widgets::menu::MenuItem_obj::__boot();
::com::arm::demo::widgets::menu::PopoutMenu_obj::__boot();
::fluid::FluidAssets_obj::__boot();
::fluid::display::FluidGraphics_obj::__boot();
::openfl::_v2::events::Event_obj::__boot();
::openfl::_v2::events::MouseEvent_obj::__boot();
::openfl::_v2::events::TouchEvent_obj::__boot();
::openfl::_v2::display::Stage_obj::__boot();
::fluid::display::FluidStage_obj::__boot();
::fluid::events::EventData_obj::__boot();
::openfl::_v2::geom::Rectangle_obj::__boot();
::fluid::geom::FluidRectangle_obj::__boot();
::openfl::_v2::text::TextField_obj::__boot();
::fluid::text::FluidText_obj::__boot();
::fluid::text::FluidTextFormat_obj::__boot();
::haxe::StackItem_obj::__boot();
::haxe::CallStack_obj::__boot();
::haxe::Resource_obj::__boot();
::haxe::Timer_obj::__boot();
::haxe::Unserializer_obj::__boot();
::haxe::ds::IntMap_obj::__boot();
::haxe::ds::ObjectMap_obj::__boot();
::haxe::ds::StringMap_obj::__boot();
::haxe::format::JsonParser_obj::__boot();
::haxe::io::BytesBuffer_obj::__boot();
::haxe::io::Eof_obj::__boot();
::haxe::io::Error_obj::__boot();
::haxe::zip::Compress_obj::__boot();
::haxe::zip::FlushMode_obj::__boot();
::haxe::zip::Uncompress_obj::__boot();
::motion::actuators::IGenericActuator_obj::__boot();
::motion::actuators::GenericActuator_obj::__boot();
::motion::actuators::SimpleActuator_obj::__boot();
::motion::easing::Expo_obj::__boot();
::motion::easing::IEasing_obj::__boot();
::motion::easing::ExpoEaseOut_obj::__boot();
::motion::Actuate_obj::__boot();
::motion::_Actuate::EffectsOptions_obj::__boot();
::motion::_Actuate::TransformOptions_obj::__boot();
::motion::_Actuate::TweenTimer_obj::__boot();
::motion::MotionPath_obj::__boot();
::motion::IComponentPath_obj::__boot();
::motion::ComponentPath_obj::__boot();
::motion::BezierPath_obj::__boot();
::motion::LinearPath_obj::__boot();
::motion::RotationPath_obj::__boot();
::motion::actuators::FilterActuator_obj::__boot();
::motion::actuators::MethodActuator_obj::__boot();
::motion::actuators::MotionPathActuator_obj::__boot();
::motion::actuators::PropertyDetails_obj::__boot();
::motion::actuators::PropertyPathDetails_obj::__boot();
::motion::actuators::TransformActuator_obj::__boot();
::motion::easing::Cubic_obj::__boot();
::motion::easing::CubicEaseIn_obj::__boot();
::motion::easing::CubicEaseInOut_obj::__boot();
::motion::easing::CubicEaseOut_obj::__boot();
::motion::easing::ExpoEaseIn_obj::__boot();
::motion::easing::ExpoEaseInOut_obj::__boot();
::msignal::Signal2_obj::__boot();
::msignal::Slot_obj::__boot();
::msignal::Slot0_obj::__boot();
::msignal::Slot1_obj::__boot();
::msignal::Slot2_obj::__boot();
::openfl::_v2::AssetCache_obj::__boot();
::openfl::_v2::Assets_obj::__boot();
::openfl::_v2::AssetData_obj::__boot();
::openfl::_v2::AssetType_obj::__boot();
::openfl::_v2::Memory_obj::__boot();
::openfl::_v2::_Vector::Vector_Impl__obj::__boot();
::openfl::_v2::display::Bitmap_obj::__boot();
::openfl::_v2::display::BitmapData_obj::__boot();
::openfl::_v2::display::OptimizedPerlin_obj::__boot();
::openfl::_v2::display::BlendMode_obj::__boot();
::openfl::_v2::display::CapsStyle_obj::__boot();
::openfl::_v2::display::DirectRenderer_obj::__boot();
::openfl::_v2::display::Graphics_obj::__boot();
::openfl::_v2::display::IGraphicsData_obj::__boot();
::openfl::_v2::display::JointStyle_obj::__boot();
::openfl::_v2::display::LineScaleMode_obj::__boot();
::openfl::_v2::display::Loader_obj::__boot();
::openfl::_v2::net::URLLoader_obj::__boot();
::openfl::_v2::display::LoaderInfo_obj::__boot();
::openfl::_v2::display::ManagedStage_obj::__boot();
::openfl::_v2::display::MovieClip_obj::__boot();
::openfl::_v2::display::OpenGLView_obj::__boot();
::openfl::_v2::display::Shape_obj::__boot();
::openfl::_v2::display::SpreadMethod_obj::__boot();
::openfl::_v2::display::TouchInfo_obj::__boot();
::openfl::_v2::display::StageQuality_obj::__boot();
::openfl::_v2::geom::Point_obj::__boot();
::openfl::_v2::display::Tilesheet_obj::__boot();
::openfl::_v2::display::TriangleCulling_obj::__boot();
::openfl::_v2::events::Listener_obj::__boot();
::openfl::_v2::events::HTTPStatusEvent_obj::__boot();
::openfl::_v2::events::KeyboardEvent_obj::__boot();
::openfl::_v2::events::SystemEvent_obj::__boot();
::openfl::_v2::filters::BitmapFilter_obj::__boot();
::openfl::_v2::geom::ColorTransform_obj::__boot();
::openfl::_v2::geom::Matrix_obj::__boot();
::openfl::_v2::geom::Transform_obj::__boot();
::openfl::_v2::gl::GL_obj::__boot();
::openfl::_v2::gl::_GL::Float32Data_Impl__obj::__boot();
::openfl::_v2::gl::GLObject_obj::__boot();
::openfl::_v2::gl::GLBuffer_obj::__boot();
::openfl::_v2::gl::GLFramebuffer_obj::__boot();
::openfl::_v2::gl::GLProgram_obj::__boot();
::openfl::_v2::gl::GLRenderbuffer_obj::__boot();
::openfl::_v2::gl::GLShader_obj::__boot();
::openfl::_v2::gl::GLTexture_obj::__boot();
::openfl::_v2::media::Sound_obj::__boot();
::openfl::_v2::media::InternalAudioType_obj::__boot();
::openfl::_v2::media::SoundChannel_obj::__boot();
::openfl::_v2::media::AudioThreadState_obj::__boot();
::openfl::_v2::net::URLRequest_obj::__boot();
::openfl::_v2::net::URLRequestMethod_obj::__boot();
::openfl::_v2::system::Capabilities_obj::__boot();
::openfl::_v2::system::PixelFormat_obj::__boot();
::openfl::_v2::system::ScreenMode_obj::__boot();
::openfl::_v2::text::Font_obj::__boot();
::openfl::_v2::text::FontStyle_obj::__boot();
::openfl::_v2::text::FontType_obj::__boot();
::openfl::_v2::text::TextFormat_obj::__boot();
::openfl::_v2::text::TextLineMetrics_obj::__boot();
::openfl::_v2::ui::Keyboard_obj::__boot();
::openfl::_v2::utils::IMemoryRange_obj::__boot();
::openfl::_v2::utils::ArrayBufferView_obj::__boot();
::openfl::_v2::utils::IDataOutput_obj::__boot();
::openfl::_v2::utils::IDataInput_obj::__boot();
::openfl::_v2::utils::ByteArray_obj::__boot();
::openfl::_v2::utils::CompressionAlgorithm_obj::__boot();
::openfl::_v2::utils::Float32Array_obj::__boot();
::openfl::_v2::utils::WeakRef_obj::__boot();
::openfl::display::FPS_obj::__boot();
::openfl::display::FrameLabel_obj::__boot();
::openfl::display::GradientType_obj::__boot();
::openfl::display::GraphicsPathWinding_obj::__boot();
::openfl::display::InterpolationMethod_obj::__boot();
::openfl::display::PixelSnapping_obj::__boot();
::openfl::display::StageAlign_obj::__boot();
::openfl::display::StageDisplayState_obj::__boot();
::openfl::display::StageScaleMode_obj::__boot();
::openfl::errors::Error_obj::__boot();
::openfl::errors::ArgumentError_obj::__boot();
::openfl::errors::EOFError_obj::__boot();
::openfl::errors::RangeError_obj::__boot();
::openfl::events::TextEvent_obj::__boot();
::openfl::events::ErrorEvent_obj::__boot();
::openfl::events::EventPhase_obj::__boot();
::openfl::events::FocusEvent_obj::__boot();
::openfl::events::IOErrorEvent_obj::__boot();
::openfl::events::JoystickEvent_obj::__boot();
::openfl::events::ProgressEvent_obj::__boot();
::openfl::events::SampleDataEvent_obj::__boot();
::openfl::events::UncaughtErrorEvent_obj::__boot();
::openfl::events::UncaughtErrorEvents_obj::__boot();
::openfl::geom::Matrix3D_obj::__boot();
::openfl::geom::Orientation3D_obj::__boot();
::openfl::geom::Vector3D_obj::__boot();
::openfl::media::ID3Info_obj::__boot();
::openfl::media::SoundLoaderContext_obj::__boot();
::openfl::media::SoundTransform_obj::__boot();
::openfl::net::URLLoaderDataFormat_obj::__boot();
::openfl::net::URLRequestHeader_obj::__boot();
::openfl::net::URLVariables_obj::__boot();
::openfl::system::ApplicationDomain_obj::__boot();
::openfl::system::LoaderContext_obj::__boot();
::openfl::system::SecurityDomain_obj::__boot();
::openfl::text::AntiAliasType_obj::__boot();
::openfl::text::GridFitType_obj::__boot();
::openfl::text::TextFieldAutoSize_obj::__boot();
::openfl::text::TextFieldType_obj::__boot();
::openfl::utils::Endian_obj::__boot();
}

