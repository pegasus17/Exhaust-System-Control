pipeline{
  agent{
    label "PlatformIO"
  }
  environment{
    PROJECT_ROOT = "ExhaustControl"
  }
  stages{
    stage("Build"){
      steps{
        dir("${PROJECT_ROOT}") {
          sh("pio run --environment uno -t clean")
          sh("pio run --environment uno")
        }
      }
    }
  }
  post{
    always{
      sh("pio system prune --force")
    }
    success{
      dir("${PROJECT_ROOT}"){
        archiveArtifacts(
          artifacts: '.pio/build/uno/firmware.hex',
          fingerprint: true,
          followSymlinks: false,
          onlyIfSuccessful: true
        )
      }
    }
    failure{
      echo "========pipeline execution failed========"
    }
  }
}