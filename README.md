# embedded-fw-test-automation
임베디드 SW 자동화 개발을 위해 이것저것 해보는 곳

펌웨어 기능을 자동으로 검증하고, 테스트 리포트를 생성하는 임베디드 품질 테스트 자동화 프로젝트입니다.
테스트 시간 줄이기가 최종 목표입니다...
에러 상황 명확히 하기도...
테스트 흐름을 수행자가 편하게 이해할 수 있는게 목표입니다...

## ✅ 주요 기능
- C로 작성된 임베디드 함수 유닛 테스트
- JSON 기반 테스트 시나리오 관리
- Python을 이용한 테스트 실행 자동화
- 시리얼 통신 및 로그 수집
- 테스트 리포트 자동 생성 (HTML)
- GitHub Actions를 통한 CI 자동화

## 💻 기술 스택
- C, Python, pytest, Allure, GitHub Actions

## 📂 프로젝트 구조
📁 embedded-fw-test-automation
├── README.md
├── firmware/
│   ├── main.c
│   └── utils.c
├── test/
│   ├── test_config.json
│   └── test_runner.py
├── reports/
│   └── latest_report.html
├── .github/
│   └── workflows/test.yml
└── requirements.txt

## 🎯 적용 가능성
- 제품 개발 단계에서 유닛 테스트 자동화
- QA 업무 효율화 및 테스트 일관성 확보
- 시뮬레이터 또는 실제 디바이스 연동 테스트
