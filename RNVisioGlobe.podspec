Pod::Spec.new do |s|
  s.name         = "react-native-visio-globe"
  s.version      = "1.0.0"
  s.summary      = "bridge for visioglobe library"
  s.homepage     = "https://github.com/author/RNVisioGlobe.git"
  s.license      = "MIT"
  s.authors      = "Sharif Fahes"

  s.platforms    = { :ios => "10.0" }
  s.source       = { :git => "https://github.com/author/RNVisioGlobe.git", :tag => "#{s.version}" }

  s.source_files = "ios/**/*.{h,m,mm,swift}"

  s.dependency "React-Core"

  # Don't install the dependencies when we run `pod install` in the old architecture.
  if ENV['RCT_NEW_ARCH_ENABLED'] == '1' then
    s.compiler_flags = folly_compiler_flags + " -DRCT_NEW_ARCH_ENABLED=1"
    s.pod_target_xcconfig    = {
        "HEADER_SEARCH_PATHS" => "\"$(PODS_ROOT)/boost\"",
        "CLANG_CXX_LANGUAGE_STANDARD" => "c++17"
    }

    s.dependency "React-Codegen"
    s.dependency "RCT-Folly"
    s.dependency "RCTRequired"
    s.dependency "RCTTypeSafety"
    s.dependency "ReactCommon/turbomodule/core"
  end
end
