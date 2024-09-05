# TTS Demo App (Qt Library)

이 앱은 Qt 라이브러리를 기반으로 개발된 PC 애플리케이션입니다.  
This app is a PC application developed based on the Qt library.  

이 애플리케이션은 직접 설계한 멀티플랫폼용 [**totsuka89/tts-lib**](https://github.com/totsuka89/tts-lib) 라이브러리를 사용하여 TTS(Text-to-Speech)의 기능을 테스트해보기 위해 제작되었습니다.  
It was created to test the TTS (Text-to-Speech) functionality using the [**totsuka89/tts-lib**](https://github.com/totsuka89/tts-lib) library, which was designed specifically for multi-platform use.

## 기능 Features
- TTS 음성 합성 (TTS voice synthesis)
- TTS 음성 합성 결과 저장 (Save TTS voice synthesis results)

## 지원 엔진 Supported Engines
- Google Cloud TTS
- Mozilla TTS (Not yet)

## 스크린샷 Screenshot
![애플리케이션 Application](https://github.com/totsuka89/tts-app-qt/blob/main/doc/app.png?raw=true)  
![파일 저장 다이얼로그 File save dialog](https://github.com/totsuka89/tts-app-qt/blob/main/doc/save.png?raw=true)  

## 외부 라이브러리 External Libraries

  - [totsuka89/tts-lib](https://github.com/totsuka89/tts-lib)  
      멀티플랫폼 C++20기반 TTS 라이브러리.  
      A multi-platform C++20-based TTS library.

  - [Qt 6.7.2](https://www.qt.io/)  
      GUI 프레임워크.  
      GUI framework.

  - [nlohmann/json](https://github.com/nlohmann/json)  
      JSON 처리 라이브러리.  
      JSON processing library.  
