set(srcs
	"bmi270_accel_gyro.cpp"
	"bmi2.c"
	"bmi270.c"
	"common.c")

idf_component_register(SRCS "${srcs}" 
                    INCLUDE_DIRS "include" "../../main/include" "../i2c/include"
					PRIV_REQUIRES driver i2c)