#version 330 core

layout (location = 0) in vec3 obj_spc_vertex_pos;
layout (location = 1) in vec3 obj_spc_N;
layout (location = 2) in vec3 k_d;

uniform mat4 model_mat;
uniform mat4 view_mat;
uniform mat4 proj_mat;

out vec3 I; 

void main() {
    vec3 cam_pos = vec3(0.0f, 0.0f, 1.5f);

    vec3 I_a = vec3(0.2f, 0.2f, 0.2f);
    vec3 k_a = vec3(0.0f, 0.0f, 1.0f);	
    vec3 k_s = vec3(1.0f, 1.0f, 1.0f);	
    vec3 I_p_pos = vec3(-2.0f, 2.0f, 1.5f);
    vec3 I_p = vec3(0.8f, 0.8f, 0.8f);
    
    // Atividade 1
    // Calculando vetores
    vec3 L = normalize(I_p_pos - (model_mat * vec4(obj_spc_vertex_pos, 1.0)).xyz); // Vetor da fonte de luz
    vec3 N = normalize(mat3(transpose(inverse(model_mat))) * obj_spc_N); // Vetor normal 

    // Atividade 2
    // Calculando vetores
    vec3 R = -reflect (L, N); // Vetore reflexão
    vec3 V = normalize(cam_pos - (model_mat * vec4(obj_spc_vertex_pos, 1.0)).xyz); // Vetor do ponto de vista

    // I = I_a * k_a; Default
    // I = I_a * k_a + I_p * k_d * dot(L, N); Atividade 1
    I = I_a * k_a + I_p * (k_d * max(dot(L, N), 0.0f) + k_s * pow(max(dot(R, V), 0.0f), 64)); 

    gl_Position = proj_mat * view_mat * model_mat * vec4(obj_spc_vertex_pos, 1.0);
}