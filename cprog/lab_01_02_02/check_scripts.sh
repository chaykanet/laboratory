#!/bin/bash

shellcheck build_debug.sh

shellcheck build_debug_asan.sh

shellcheck build_debug_msan.sh

shellcheck build_debug_ubsan.sh

shellcheck build_gcov.sh

shellcheck collect_coverage.sh

shellcheck build_release.sh

shellcheck ./func_tests/scripts/comparator.sh

shellcheck ./func_tests/scripts/func_tests.sh

shellcheck ./func_tests/scripts/pos_case.sh

shellcheck ./func_tests/scripts/neg_case.sh