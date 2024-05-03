set(srcs
	"bmi2.c"
	"bmi270.c"
	"bmi270_library.cpp"
	"bmi270_reading_i2c.cpp")

idf_component_register(SRCS "${srcs}" 
                    INCLUDE_DIRS "include" "../../main/include" "../i2c/include"
					PRIV_REQUIRES driver i2c)