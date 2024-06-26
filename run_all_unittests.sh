cat << "EOF"
=====================================================================
	  ____ _                          _
	 / ___| |__   __ _ _ __ ___   ___| | ___  ___  _ __
	| |   | '_ \ / _` | '_ ` _ \ / _ \ |/ _ \/ _ \| '_ \
	| |___| | | | (_| | | | | | |  __/ |  __/ (_) | | | |
	 \____|_| |_|\__,_|_| |_| |_|\___|_|\___|\___/|_| |_|

	 _   _       _ _   _            _
	| | | |_ __ (_) |_| |_ ___  ___| |_ ___
	| | | | '_ \| | __| __/ _ \/ __| __/ __|
	| |_| | | | | | |_| ||  __/\__ \ |_\__ \
	 \___/|_| |_|_|\__|\__\___||___/\__|___/
=====================================================================

EOF

cat <<EOF
=================================
* Test with configs: gc=enable *
=================================
EOF
#bazel test $(bazel query //...) -c dbg --build_tests_only --//:gc=enable

cat <<EOF
=================================
* Test with configs: gc=disable *
=================================
EOF
bazel test $(bazel query //...) -c dbg --build_tests_only --//:gc=disable
