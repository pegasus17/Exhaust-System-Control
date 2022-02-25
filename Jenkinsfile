pipeline{
  agent{
    label "PlatformIO"
  }
  stages{
    stage("Build"){
      steps{
        dir("ExhaustControl") {
          sh("pio run -v")
        }
      }
    }
  }
  post{
    always{
      sh("pio system prune --force")
    }
    success{
      archiveArtifacts(
        artifacts: '.pio/build/uno/firmware.hex',
        fingerprint: true,
        followSymlinks: false,
        onlyIfSuccessful: true
      )
    }
    failure{
      echo "========pipeline execution failed========"
    }
  }
}